#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTextDocument>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QVBoxLayout>

class NoteEditor : public QObject
{
public:
    //Inherits from QObject, enabling signals & slots
    Q_OBJECT
    //Open editor from file

public:
    NoteEditor(QMainWindow* w, QString fn);

    QWidget* holder; // Holder for all child widgets, maybe an awful thing but eh
    QVBoxLayout* layout; // Application layout
    QStackedWidget* stack; // Container for the editor & viewer
    QPlainTextEdit* editor; // Actual text editor
    QTextBrowser* viewer;   // MD Viewer
    QPushButton* switchBtn; // View switcher button
    QTextDocument* currentDocument; //document currently open

public slots:
    void SwitchViews(void);

private:
    QPushButton* btn;

protected:


};

#endif // NOTEEDITOR_H
