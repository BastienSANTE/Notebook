#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTextDocument>
#include <QPlainTextEdit>
#include <QTextBrowser>

class NoteEditor
{
public:
    NoteEditor();

    QTextDocument* currentDocument; //List of documents currently open

    QPlainTextEdit* editor;
    QTextBrowser* viewer;

    QPushButton* switchBtn;

    void Setup(QMainWindow* mainWindow);

private:
    QPushButton* btn;

protected:


};

#endif // NOTEEDITOR_H
