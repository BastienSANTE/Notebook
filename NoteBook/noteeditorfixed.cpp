#include "noteeditorfixed.h"

NoteEditorFixed::NoteEditorFixed(MainWindow *w, DocumentList* dl, QString fn) : QObject(w) {
    BaseSetup(w);

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
    }

    QTextDocument* doc = new QTextDocument();
    doc->setPlainText(QString(openedFile.readAll()));
    dl->AddDocument(doc);
    editor->setDocument(doc);
    editor->setPlainText(doc->toPlainText());
    doc->setMetaInformation(QTextDocument::DocumentTitle, fn);
    openedFile.close();
}

NoteEditorFixed::NoteEditorFixed(MainWindow* w, DocumentList* dl) : QObject(w) {
    BaseSetup(w);

    QTextDocument* emptyFile = new QTextDocument();
    editor->setPlainText(emptyFile->toPlainText());
    emptyFile->setMetaInformation(QTextDocument::DocumentTitle, "Unsaved");

    dl->AddDocument(emptyFile);
}

void NoteEditorFixed::BaseSetup(MainWindow* w) {
    holder = new QWidget(w);
    holder->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    layout =  new QVBoxLayout(holder);
    stack = new QStackedWidget(holder);

    stack->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    editor = new QPlainTextEdit(holder);
    viewer = new QTextBrowser(holder);
    switchBtn = new QPushButton("Switch", w);
    saveBtn = new QPushButton("Save", w);
    stack->addWidget(editor);
    stack->addWidget(viewer);

    layout->addWidget(stack, 1, Qt::AlignCenter);
    layout->addWidget(switchBtn, 0, Qt::AlignCenter);

    connect(switchBtn, &QPushButton::clicked, this, &NoteEditorFixed::SwitchViews);
    connect(saveBtn, &QPushButton::clicked, this, &NoteEditorFixed::Save);

    w->setCentralWidget(holder);
    w->centralWidget()->setContentsMargins(0,0,0,0);
}

void NoteEditorFixed::SwitchViews() {
    if(stack->currentIndex() == 0) {
        stack->setCurrentIndex(1);
        viewer->setMarkdown(editor->toPlainText());
        switchBtn->setText("Plain View");
    } else {
        stack->setCurrentIndex(0);
        switchBtn->setText("MD view");
    }
}

void NoteEditorFixed::Save() {
    qDebug() << "Save button clicked";
    QTextDocument* doc = editor->document();
    QString fn = GetCurrentDocumentTitle();

    if (QFile::exists(fn)) {

        QFile savedFile(fn);

        if (!savedFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&savedFile);
        stream << editor->toPlainText();
        savedFile.close();
        qDebug() << "Wrote to " << doc->metaInformation(QTextDocument::DocumentTitle);

    } else {
        QFile newFile("Untitled.md");

        if (!newFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream output(&newFile);
        output << editor->toPlainText() ;
        newFile.close();
        qDebug() << "Wrote to Untitled.md";
    }
}
