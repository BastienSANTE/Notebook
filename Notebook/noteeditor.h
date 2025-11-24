#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <iostream>
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
    //Inherits from QObject, enabling signals & slots
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
        holder = new QWidget(w);
        w->setCentralWidget(holder);
        w->centralWidget()->setContentsMargins(0, 0, 0, 0);
        layout =  new QVBoxLayout(holder);
        stack = new QStackedWidget(holder);
        editor = new QPlainTextEdit(stack);
        viewer = new QTextBrowser(stack);
        switchBtn = new QPushButton("Switch", w);
        saveBtn = new QPushButton("Save", w);
        stack->addWidget(editor);
        stack->addWidget(viewer);

        layout->addWidget(stack, 1, Qt::AlignCenter);
        layout->addWidget(switchBtn, 0, Qt::AlignCenter);

        QFile argumentFile(fn);
        QTextDocument* startUpFile;


        if (argumentFile.open(QIODeviceBase::ReadWrite)) {
            startUpFile = new QTextDocument();
            startUpFile->setPlainText(QString(argumentFile.readAll()));
            editor->setDocument(startUpFile);
            editor->setPlainText(startUpFile->toPlainText());
            startUpFile->setMetaInformation(QTextDocument::DocumentTitle, fn);
        }

        dl->AddDocumentToList(startUpFile);

        argumentFile.close();

        QObject::connect(switchBtn, SIGNAL(clicked()), this, SLOT(SwitchViews()));
        QObject::connect(saveBtn, SIGNAL(clicked()), this, SLOT(Save()));
    }


    NoteEditor(QMainWindow* w, DocumentList* dl) {
        qDebug() << "Started app without a file";
        holder = new QWidget(w);
        w->setCentralWidget(holder);
        w->centralWidget()->setContentsMargins(0, 0, 0, 0);
        layout =  new QVBoxLayout(holder);
        stack = new QStackedWidget(holder);
        editor = new QPlainTextEdit(stack);
        viewer = new QTextBrowser(stack);

        switchBtn = new QPushButton("A", w);
        saveBtn = new QPushButton("Save", w);

        stack->addWidget(editor);
        stack->addWidget(viewer);

        layout->addWidget(stack, 1, Qt::AlignCenter);
        layout->addWidget(switchBtn, 0, Qt::AlignCenter);
        layout->addWidget(saveBtn, 0, Qt::AlignCenter);

        QTextDocument* startUpFile = new QTextDocument();
        editor->setPlainText(startUpFile->toPlainText());
        startUpFile->setMetaInformation(QTextDocument::DocumentTitle, "Unsaved");

        dl->AddDocumentToList(startUpFile);

        connect(switchBtn, SIGNAL(clicked()), this, SLOT(SwitchViews()));
        connect(saveBtn, SIGNAL(clicked()), this, SLOT(Save()));
    }


    ~NoteEditor() {}

public slots:
    void SwitchViews(void) {
        if(stack->currentIndex() == 0) {
            stack->setCurrentIndex(1);
            viewer->setMarkdown(editor->document()->toPlainText());
            switchBtn->setText("Plain View");
        } else {
            stack->setCurrentIndex(0);
            switchBtn->setText("MD view");
        }
    };

    void Save(){

        QTextDocument* doc = editor->document();

        if (QFile::exists(doc->metaInformation(QTextDocument::DocumentTitle))) {
            QFile saveFile(editor->documentTitle());

            if (saveFile.open(QIODevice::Append | QIODevice::Text)){
                QTextStream output(&saveFile);
                output << editor->toPlainText() ;
                saveFile.close();
                qDebug() << "Wrote to " << doc->metaInformation(QTextDocument::DocumentTitle);
            }

        } else {
            QFile saveFile("Untitled.md");
            saveFile.setFileName("Untitled.md");

            if (saveFile.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream output(&saveFile);
                output << editor->toPlainText() ;
                saveFile.close();
                qDebug() << "Wrote to Untitled.md";
            }
        }
    };

private:

};

#endif // NOTEEDITOR_H
