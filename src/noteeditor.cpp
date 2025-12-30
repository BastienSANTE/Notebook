#include "noteeditor.h"

Editor::Editor(QString fn) {
    BaseSetup();

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
    }
}

Editor::Editor() {
    BaseSetup();
    CreateEmptyPage();
}

void Editor::BaseSetup() {
    mainWindow = new QMainWindow(nullptr);
    uiFrame = new QFrame(mainWindow);
    layout = new QVBoxLayout(uiFrame);
    uiFrame->setLayout(layout);

    mainWindow->setCentralWidget(uiFrame);
    mainWindow->centralWidget()->setContentsMargins(0,0,0,0);

    fileMenu = new QMenu("File", mainWindow);
    openFileAction = new QAction("Open File", this);
    fileMenu->addAction(openFileAction);
    mainWindow->menuBar()->addMenu(fileMenu);

    editor = new QTextEdit(nullptr);
    browser = new NoteBrowser(nullptr);
    stackSwitcher = new QStackedWidget(uiFrame);

    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    buttonBox = new QHBoxLayout(uiFrame);
    stackLayout = new QHBoxLayout(uiFrame);

    switchBtn = new QPushButton("Switch", uiFrame);
    saveBtn = new QPushButton("Save", uiFrame);
    addPageBtn = new QPushButton("New Document", uiFrame);
    closePageBtn = new QPushButton("Delete Document", uiFrame);

    layout->addLayout(stackLayout, 90);
    layout->addLayout(buttonBox, 10);

    buttonBox->addWidget(switchBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(saveBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(addPageBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(closePageBtn, 1, Qt::AlignCenter);

    stackLayout->addWidget(stackSwitcher);

    switchShortcut = new QShortcut(QKeySequence("Ctrl+R"), this->mainWindow);

    connect(switchShortcut, &QShortcut::activated, this, &Editor::SwitchViews);
    connect(switchBtn, &QPushButton::clicked, this, &Editor::SwitchViews);
    connect(saveBtn, &QPushButton::clicked, this, &Editor::Save);
    connect(addPageBtn, &QPushButton::clicked, this, &Editor::CreateEmptyPage);

    // Create regular expression to match
    // WHAT THE FUCK HAVE I DONE
    //latexRE = new QRegularExpression("/(?<=(\${2}\\\\)|(\${2})).*(?<=\${2})|(?<=\${2}\\\\)");
    latexRE = new QRegularExpression("(?=\\${2}).*(?<=\\${2})");
}

void Editor::OpenFile(){
    QString fn = QFileDialog::getOpenFileName(mainWindow, "Open File", "/", "Files (*.md)");

    if (fn.isEmpty()) return;

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
        return;
    }

    CreatePageFromFile(openedFile);
}

//Create an empty QTextBrowser
void Editor::CreateEmptyPage() {
    NoteEditorPage* newPage = new NoteEditorPage(mainWindow);
    SetCurrentPage(newPage);
}

// Create new QTextBrowser with contents of openedFile
// Function modified to be able to keep a reference to file path
void Editor::CreatePageFromFile(QFile& openedFile) {
    NoteEditorPage* newPage = new NoteEditorPage(mainWindow, openedFile.fileName(), openedFile.readAll());
    SetCurrentPage(newPage);
}

void Editor::SwitchViews() {

    if(stackSwitcher->currentIndex() == 0) {
        qDebug() << "Showing MD view";
        switchBtn->setText("Plain View");
        RenderDocument(GetCurrentPage()->document);
        stackSwitcher->setCurrentIndex(1);
    } else {
        stackSwitcher->setCurrentIndex(0);
        qDebug() << "Showing plain view";
        switchBtn->setText("MD view");
    }
}


void Editor::Save() {
    qDebug() << "Save button clicked";
    QTextDocument* doc = GetCurrentPage()->document;
    QString fn = GetCurrentPage()->documentPath.toString();

    if (QFile::exists(fn)) {

        QFile savedFile(fn);

        if (!savedFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&savedFile);
        stream << GetCurrentPage()->document->toPlainText();
        savedFile.close();
        qDebug() << "Wrote to " << fn;

    } else {
        QFile newFile("Untitled.md");

        if (!newFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&newFile);
        stream << GetCurrentPage()->document->toPlainText();
        newFile.close();
        qDebug() << "Wrote to Untitled.md";
    }
}


void Editor::SetupMathDocumentObject(){
    QObject* mathDocumentInterface = new MathDocumentObject(this);
    GetCurrentPage()->renderDocument->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentInterface);
}

/* TODO : Implement a function to count the number of
LaTeX elements in the document as a test */
void Editor::RenderDocument(QTextDocument* doc){
    // Clear text doc before new render
    doc = GetCurrentPage()->document;
    QTextDocument* rdoc = GetCurrentPage()->renderDocument;

    rdoc->clear();

    // Render the basic elements as Markdown
    rdoc->setMarkdown(doc->toPlainText(), QTextDocument::MarkdownDialectGitHub);

    // Get all of the text as one large QString
    QString documentText = rdoc->toPlainText();

    QTextCursor cursor(rdoc);
    JKQTMathText* mathRender = new JKQTMathText(this);

    bool _lastParseResult = true;

    while(_lastParseResult) {
    cursor = rdoc->find(*latexRE, cursor);
    QString matchText = cursor.selectedText();

        if (matchText == "") {
            _lastParseResult = false;
        }

        cursor.removeSelectedText();
        qDebug() << matchText;

        if (mathRender->parse(matchText)) {
            cursor.insertText(QString(QChar::ObjectReplacementCharacter), MathDocumentObject::GenerateFormat(mathRender));
        }
    }

    delete (mathRender);
}
