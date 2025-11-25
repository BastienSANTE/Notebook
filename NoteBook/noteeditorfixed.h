#ifndef NOTEEDITORFIXED_H
#define NOTEEDITORFIXED_H

#include <QObject>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextBrowser>
#include <Qfile>
#include "documentlist.h"

class NoteEditorFixed : public QObject
{
    Q_OBJECT

public:
    explicit NoteEditorFixed(QMainWindow* w, DocumentList* dl,  QString fn);
    explicit NoteEditorFixed(QMainWindow* w, DocumentList* dl);

    QWidget* holder; // Holder for all child widgets, maybe an awful thing but eh
    QVBoxLayout* layout; // Application layout
    QStackedWidget* stack; // Container for the editor & viewer
    QPlainTextEdit* editor; // Actual text editor
    QTextBrowser* viewer;   // MD Viewer
    QPushButton* switchBtn; // View switcher button
    QPushButton* saveBtn;   // Save file button
    QTextDocument* currentDocument; //document currently open

    void BaseStup(QMainWindow* w);
    QString GetCurrentDocumentTitle() const { return editor->documentTitle(); }

signals:

public slots:
    void SwitchViews();

    void Save();
};

#endif // NOTEEDITORFIXED_H
