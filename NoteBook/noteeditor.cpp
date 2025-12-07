#include "noteeditor.h"

Editor::Editor(QString fn) {
    BaseSetup();

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
    }

    CreateTabFromFile(openedFile);
    openedFile.close();
}

Editor::Editor() {
    BaseSetup();
    AddTab();
}

void Editor::BaseSetup() {
    mainWindow = new QMainWindow(nullptr);
    uiFrame = new QFrame(mainWindow);
    layout = new QVBoxLayout(uiFrame);
    uiFrame->setLayout(layout);

    mainWindow->setCentralWidget(uiFrame);
    mainWindow->centralWidget()->setContentsMargins(0,0,0,0);

    tabBox = new QHBoxLayout(uiFrame);
    buttonBox = new QHBoxLayout(uiFrame);
    tabs = new QTabWidget(uiFrame);

    switchBtn = new QPushButton("Switch", tabs);
    saveBtn = new QPushButton("Save", tabs);
    addTabBtn = new QPushButton("New Tab", tabs);
    deleteTabBtn = new QPushButton("Delete Tab", tabs);

    layout->addLayout(tabBox, 90);
    layout->addLayout(buttonBox, 10);

    tabBox->addWidget(tabs, 1, Qt::Alignment());

    buttonBox->addWidget(switchBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(saveBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(addTabBtn, 1, Qt::AlignCenter);
    buttonBox->addWidget(deleteTabBtn, 1, Qt::AlignCenter);

    connect(switchBtn, &QPushButton::clicked, this, &Editor::SwitchViews);
    connect(saveBtn, &QPushButton::clicked, this, &Editor::Save);
    connect(addTabBtn, &QPushButton::clicked, this, &Editor::AddTab);
}

//Create an empty QTextBrowser
void Editor::AddTab() {
    NoteEditorTab* newTab = new NoteEditorTab(tabs);
    tabs->addTab(newTab, "Untitled");
}

// Create new QTextBrowser with contents of openedFile
// Function modified to be able to keep a reference to file path
void Editor::CreateTabFromFile(QFile& openedFile) {
    NoteEditorTab* newFileTab = new NoteEditorTab(tabs, openedFile.fileName(), openedFile.readAll());
    tabs->addTab(newFileTab, openedFile.fileName());
}

void Editor::SwitchViews() {
    QStackedWidget* switcher = GetCurrentTab()->stackSwitcher;

    if(switcher->currentIndex() == 0) {
        switcher->setCurrentIndex(1);
        qDebug() << "Showing MD view";
        switchBtn->setText("Plain View");
        GetCurrentTab()->document->setMarkdown(GetCurrentTab()->editor->toPlainText(), QTextDocument::MarkdownDialectGitHub);
        GetCurrentTab()->browser->setMarkdown(GetCurrentTab()->editor->toPlainText());
    } else {
        switcher->setCurrentIndex(0);
        qDebug() << "Showing plain view";
        switchBtn->setText("MD view");
    }
}


void Editor::Save() {
    qDebug() << "Save button clicked";
    QTextDocument* doc = GetCurrentDocument();
    QString fn = GetCurrentTabTitle();

    if (QFile::exists(fn)) {

        QFile savedFile(fn);

        if (!savedFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&savedFile);
        stream << GetCurrentTab()->editor->toPlainText();
        savedFile.close();
        qDebug() << "Wrote to " << fn;

    } else {
        QFile newFile("Untitled.md");

        if (!newFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&newFile);
        stream << GetCurrentTab()->editor->toPlainText();
        newFile.close();
        qDebug() << "Wrote to Untitled.md";
    }
}
