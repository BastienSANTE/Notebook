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
    CreateTab();
}

void Editor::BaseSetup() {
    mainWindow = new QMainWindow(nullptr);
    uiHolder = new QWidget(mainWindow);
    tabs = new QTabWidget(mainWindow);
    layout = new QVBoxLayout(uiHolder);
    mainWindow->setCentralWidget(uiHolder);

    switchBtn = new QPushButton("Switch", tabs);
    saveBtn = new QPushButton("Save", tabs);

    layout->addWidget(tabs, 1, Qt::AlignCenter);
    layout->addWidget(saveBtn, 1, Qt::AlignCenter);
    layout->addWidget(switchBtn, 1, Qt::AlignCenter);

    connect(switchBtn, &QPushButton::clicked, this, &Editor::SwitchViews);
    connect(saveBtn, &QPushButton::clicked, this, &Editor::CreateTab);
}

//Create an empty QTextBrowser
void Editor::CreateTab() {
    NoteEditorTab* newTab = new NoteEditorTab(nullptr);
    tabs->addTab(newTab, "Untitled");
}

// Create new QTextBrowser with contents of openedFile
void Editor::CreateTabFromFile(QFile& openedFile) {
    NoteEditorTab* newFileTab = new NoteEditorTab(nullptr, openedFile.readAll());
    tabs->addTab(newFileTab, openedFile.fileName());
}

void Editor::SwitchViews() {
    QStackedWidget* switcher = GetCurrentTab()->stackSwitcher;

    if(switcher->currentIndex() == 0) {
        switcher->setCurrentIndex(1);
        qDebug() << "Showing MD view";
        switchBtn->setText("Plain View");
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
        qDebug() << "Wrote to " << doc->metaInformation(QTextDocument::DocumentTitle);

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
