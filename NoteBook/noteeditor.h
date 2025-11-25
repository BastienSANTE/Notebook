#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QDebug>
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTextDocument>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include "documentlist.h"

class NoteEditor : public QObject
{
public:
    Q_OBJECT

public:
    QWidget* holder; // Holder for all child widgets, maybe an awful thing but eh
    QVBoxLayout* layout; // Application layout
    QStackedWidget* stack; // Container for the editor & viewer
    QPlainTextEdit* editor; // Actual text editor
    QTextBrowser* viewer;   // MD Viewer
    QPushButton* switchBtn; // View switcher button
    QPushButton* saveBtn;   // Save file button
    QTextDocument* currentDocument; //document currently open

    NoteEditor(QMainWindow* w, DocumentList* dl,  QString fn) {
        BaseSetup(w);

        QFile openedFile(fn);

        if (!(openedFile.open(QIODeviceBase::ReadWrite))) {
            qDebug() << "Error : File could not be opened";
        }

        QObject::connect(saveBtn, &QPushButton::clicked, this, &NoteEditor::Save);
        QTextDocument* doc = new QTextDocument();
        doc->setPlainText(QString(openedFile.readAll()));
        dl->AddDocument(doc);
        editor->setDocument(doc);
        editor->setPlainText(doc->toPlainText());
        doc->setMetaInformation(QTextDocument::DocumentTitle, fn);
        openedFile.close();
    }

    NoteEditor(QMainWindow* w, DocumentList* dl) {
        BaseSetup(w);

        QObject::connect(saveBtn, &QPushButton::clicked, this, &NoteEditor::Save);
        QTextDocument* emptyFile = new QTextDocument();
        editor->setPlainText(emptyFile->toPlainText());
        emptyFile->setMetaInformation(QTextDocument::DocumentTitle, "Unsaved");

        dl->AddDocument(emptyFile);
    }

    ~NoteEditor() {}

    bool BaseSetup(QMainWindow* w) {
        holder = new QWidget(w);
        w->setCentralWidget(holder);
        w->centralWidget()->setContentsMargins(0, 0, 0, 0);
        layout =  new QVBoxLayout(holder);
        stack = new QStackedWidget(holder);
        editor = new QPlainTextEdit(holder);
        viewer = new QTextBrowser(holder);
        switchBtn = new QPushButton("Switch", w);
        saveBtn = new QPushButton("Save", w);
        stack->addWidget(editor);
        stack->addWidget(viewer);

        layout->addWidget(stack, 1, Qt::AlignCenter);
        layout->addWidget(switchBtn, 0, Qt::AlignCenter);

        bool connected = QObject::connect(switchBtn, SIGNAL(clicked()), this, SLOT(SwitchViews()));
        qDebug() << connected;
        return connected;
    }

    QString GetCurrentDocumentTitle() const { return editor->documentTitle(); }

public slots:
    void SwitchViews() {
        qDebug() << "Switching views";
        /*if(stack->currentIndex() == 0) {
            stack->setCurrentIndex(1);
            viewer->setMarkdown(editor->toPlainText());
            switchBtn->setText("Plain View");
        } else {
            stack->setCurrentIndex(0);
            switchBtn->setText("MD view");
        }*/
    }

    void Save() {
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
};

#endif // NOTEEDITOR_H
