#include "noteeditorfixed.h"

NoteEditorFixed::NoteEditorFixed(QMainWindow *w, DocumentList* dl, QString fn) {
    BaseSetup(w);

    QFile openedFile(fn);

    if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
        qDebug() << "Error : File could not be opened";
    }

    //QObject::connect(saveBtn, &QPushButton::clicked, this, &NoteEditorFixed::Save);
    QTextDocument* doc = new QTextDocument();
    doc->setPlainText(QString(openedFile.readAll()));
    dl->AddDocument(doc);
    editor->setDocument(doc);
    editor->setPlainText(doc->toPlainText());
    doc->setMetaInformation(QTextDocument::DocumentTitle, fn);
    openedFile.close();
}

NoteEditorFixed::NoteEditorFixed(QMainWindow* w, DocumentList* dl) {
    BaseSetup(w);

    //QObject::connect(saveBtn, &QPushButton::clicked, this, &NoteEditorFixed::Save);
    QTextDocument* emptyFile = new QTextDocument();
    editor->setPlainText(emptyFile->toPlainText());
    emptyFile->setMetaInformation(QTextDocument::DocumentTitle, "Unsaved");

    dl->AddDocument(emptyFile);
}

void NoteEditorFixed::BaseSetup(QMainWindow* w) {
    holder = new QWidget(w);
    w->setCentralWidget(holder);
    w->centralWidget()->setContentsMargins(0, 0, 0, 0);
    layout =  new QVBoxLayout(holder);
    stack = new QStackedWidget(holder);
    editor = new QPlainTextEdit(holder);
    viewer = new QTextBrowser(holder);
    switchBtn = new QPushButton("Switch", w);
    bool connected = QObject::connect(switchBtn, &QPushButton::clicked, this, &NoteEditorFixed::SwitchViews);
    qDebug() << connected;
    saveBtn = new QPushButton("Save", w);
    stack->addWidget(editor);
    stack->addWidget(viewer);

    layout->addWidget(stack, 1, Qt::AlignCenter);
    layout->addWidget(switchBtn, 0, Qt::AlignCenter);

    //bool connected = QObject::connect(switchBtn, SIGNAL(clicked()), this, SLOT(SwitchViews()));
}

void NoteEditorFixed::SwitchViews() {
    /*if(stack->currentIndex() == 0) {
        stack->setCurrentIndex(1);
        viewer->setMarkdown(editor->toPlainText());
        switchBtn->setText("Plain View");
    } else {*/
        stack->setCurrentIndex(0);
        switchBtn->setText("MD view");
    /*}*/
}

void NoteEditorFixed::Save() {
    qDebug() << "Save button clicked";
    QTextDocument* doc = editor->document();
    QString fn = GetCurrentDocumentTitle();

    if (QFile::exists(fn)) {

        QFile savedFile(fn);

        if (!savedFile.open(QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Could not save file";
        }

        QTextStream stream(&savedFile);
        stream << editor->toPlainText();
        savedFile.close();
        qDebug() << "Wrote to " << doc->metaInformation(QTextDocument::DocumentTitle);

    } else {
        QFile newFile("Untitled.md");
        QTextStream output(&newFile);
        output << editor->toPlainText() ;
        newFile.close();
        qDebug() << "Wrote to Untitled.md";
    }
}
