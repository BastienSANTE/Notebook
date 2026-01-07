#include "noteeditor.h"

Editor::Editor(QString fn) {
    BaseSetup();

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
    }

    CreateTabFromFile(openedFile);
}

Editor::Editor() {
    BaseSetup();

    AddTab();
}

// This setup function is identical, whether it launches with or without a file
void Editor::BaseSetup() {
    mainWindow = new QMainWindow(nullptr);
    uiFrame = new QFrame(mainWindow);
    layout = new QVBoxLayout(uiFrame);
    layout->setContentsMargins(0, 0, 0, 0);
    uiFrame->setLayout(layout);

    mainWindow->setCentralWidget(uiFrame);
    mainWindow->centralWidget()->setContentsMargins(0,0,0,0);

    tabBox = new QHBoxLayout(uiFrame);
    tabBox->setContentsMargins(0, 0, 0, 0);
    tabs = new QTabWidget(uiFrame);

    fsModel = new QFileSystemModel;
    fsModel->setRootPath(QDir::home().path());
    fsModel->setNameFilters({"*.md"});
    tree = new QTreeView(uiFrame);
    tree->setHeaderHidden(true);

    //tree->setColumnHidden(1, true);
    tree->setModel(fsModel);

    splitter = new QSplitter(uiFrame);
    splitter->setHandleWidth(0);
    splitter->addWidget(tree);
    splitter->addWidget(tabs);

    switchShortcut = new QShortcut(QKeySequence("Ctrl+R"), mainWindow);
    saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), mainWindow);
    addTabShortcut = new QShortcut(QKeySequence("Ctrl+N"), mainWindow);
    removeTabShortcut = new QShortcut(QKeySequence("Ctrl+K"), mainWindow);

    fileMenu = new QMenu("File", mainWindow);
    openFileAction = new QAction("Open File", this);
    fileMenu->addAction(openFileAction);
    mainWindow->menuBar()->addMenu(fileMenu);

    layout->addWidget(splitter);
    //tabBox->addWidget(tabs, 1, Qt::Alignment());

    latexRE = new QRegularExpression("(?=\\${2}).*(?<=\\${2})");

    connect(tree, &QTreeView::doubleClicked, this, qOverload<QModelIndex>(&Editor::OpenFile));
    connect(switchShortcut, &QShortcut::activated, this, &Editor::SwitchViews);
    connect(saveShortcut, &QShortcut::activated, this, &Editor::Save);
    connect(addTabShortcut, &QShortcut::activated, this, &Editor::AddTab);
    connect(removeTabShortcut, &QShortcut::activated, this, &Editor::RemoveCurrentTab);
    connect(openFileAction, &QAction::triggered, this, qOverload<>(&Editor::OpenFile));
}

//Create an empty QTextBrowser
void Editor::AddTab() {
    NoteEditorTab* newTab = new NoteEditorTab(tabs);
    connect(newTab->browser, &QTextBrowser::anchorClicked, this, qOverload<const QUrl&>(&Editor::FollowLink));
    tabs->addTab(newTab, "Untitled");
    tabs->setCurrentWidget(newTab);
}


void CreateTabFromModelIndex(){

}

// Create new QTextBrowser with contents of openedFile
// Function modified to be able to keep a reference to file path
void Editor::CreateTabFromFile(QFile& openedFile) {

    QFileInfo fileInfo(openedFile);
    NoteEditorTab* newFileTab = new NoteEditorTab(tabs, openedFile.fileName(), openedFile.readAll());
    connect(newFileTab->browser, &QTextBrowser::anchorClicked, this, qOverload<const QUrl&>(&Editor::FollowLink));
    tabs->addTab(newFileTab, openedFile.fileName());
    tabs->setCurrentWidget(newFileTab);
    openedFile.close();
}

void Editor::RemoveCurrentTab(){
    // Unique pointer to make sure the box is killed at the end
    std::unique_ptr<QMessageBox> msgBox = std::make_unique<QMessageBox>(mainWindow);

    if(!GetCurrentTab()->GetIsAFile()){
        msgBox->setText("This document is not saved on disk.");
        msgBox->setDetailedText("Do you wish to create a file ?");
    } else {
        msgBox->setText("This file was modified.");
        msgBox->setDetailedText("Do you wish to save ?");
    }

    msgBox->setStandardButtons(QMessageBox::Save |
                               QMessageBox::Discard |
                               QMessageBox::Cancel);

    int selection = msgBox->exec();

    switch(selection){
        case QMessageBox::Save:
            Save();
            tabs->removeTab(tabs->currentIndex());
            break;
        case QMessageBox::Discard:
            tabs->removeTab(tabs->currentIndex());
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }
}

void Editor::SwitchViews() {
    QStackedWidget* switcher = GetCurrentTab()->stackSwitcher;

    if(switcher->currentIndex() == 0) {
        qDebug() << "Showing MD view";
        GetCurrentTab()->RenderDocument();
        switcher->setCurrentIndex(1);

    } else {
        switcher->setCurrentIndex(0);
        qDebug() << "Showing plain view";
    }
}

void Editor::SetTabTitle(QString title){
    tabs->setTabText(tabs->currentIndex(), title);
}

void Editor::Save() {
    NoteEditorTab* tab = GetCurrentTab();
    QTextDocument* doc = tab->document;
    QString fn = GetCurrentTabTitle();

    if (tab->GetDocumentModified() == true){
        qDebug() << "Document was modified";
    }

    if (!tab->GetIsAFile()) {
        QString newFileName = QFileDialog::getSaveFileName(mainWindow, "Save As");
        QFile newFile(newFileName);

        if (!newFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&newFile);
        stream << tab->editor->toPlainText();
        SetTabTitle(newFileName);
        tab->SetIsAFile(true);
        newFile.close();

    } else {

        QFile savedFile(fn);

            if (!savedFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
                qDebug() << "Could not save file";
            }

        QTextStream stream(&savedFile);
        stream << tab->editor->toPlainText();
        savedFile.close();
        qDebug() << "Wrote to " << fn;
        tab->SetIsAFile(true);
    }
}


void Editor::OpenFile(){
    QString fn = QFileDialog::getOpenFileName(mainWindow, "Open File", "/", "Files (*.md)");

    if (fn.isEmpty()) return;

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
        return;
    }

    CreateTabFromFile(openedFile);
}

void Editor::OpenFile(QModelIndex idx){
    QString fn = fsModel->fileInfo(idx).absoluteFilePath();

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
        return;
    }

    CreateTabFromFile(openedFile);
}

void Editor::FollowLink(const QUrl& followedFile){
    Save();

    QUrl resolvedURL = GetCurrentTab()->document->baseUrl().resolved(followedFile);
    qDebug() << "The resolved URL is" << resolvedURL.toString();

    QString filePath(resolvedURL.toString());
    qDebug() << filePath;


    if(!filePath.isEmpty()) {

        QFile openedFile(filePath);

        if(!openedFile.exists()) {
            qDebug() << filePath << " does not exist.";
                return;
        }

        if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
            qDebug() << "Error : File could not be opened";
            return;
        }

        GetCurrentTab()->renderDocument->setBaseUrl(resolvedURL);
        GetCurrentTab()->document->setBaseUrl(resolvedURL);
        GetCurrentTab()->editor->setPlainText(openedFile.readAll());
        GetCurrentTab()->browser->setSource(resolvedURL);
        GetCurrentTab()->RenderDocument();

        openedFile.close();
    }


    SetTabTitle(filePath);
}
