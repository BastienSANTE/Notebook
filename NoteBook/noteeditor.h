#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTextDocument>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QStackedWidget>

class NoteEditor
{
public:
    NoteEditor(QWidget* parent);

    //Open editor from file 
    NoteEditor(QWidget* parent, char* fn);

  
    QTextDocument* currentDocument; //document currently open
    QPlainTextEdit* editor;
    QTextBrowser* viewer;
    QPushButton* switchBtn;
    QStackedWidget* stack;
  
    void SwitchViews();
  
private:
    QPushButton* btn;

protected:


};

#endif // NOTEEDITOR_H
