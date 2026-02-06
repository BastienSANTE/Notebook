#ifndef NOTEEDITORTAB_H
#define NOTEEDITORTAB_H

#include <QWidget>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QStackedWidget>
#include <QPlainTextEdit>
#include <QBoxLayout>
#include "markdownhighlighter.h"
#include "markdowntextedit.h"

/* Class for the note editor tabs. Each tab contains an editor widget &
 * viewer widget, and manages its document. If the tab is closed, it is
 * destroyed and the user is asked to save if the document is not empty.
 */

class NoteEditorTab : public QWidget
{
public:
    Q_OBJECT

public:
    explicit NoteEditorTab(QWidget *parent = nullptr);
    explicit NoteEditorTab(QWidget* parent, QString fileName, QString contents);

    ~NoteEditorTab();
    QHBoxLayout* tabContentsLayout;
    MarkdownTextEdit* editor;
    QTextDocument* document;
    QTextDocument* renderDocument;
    QAbstractTextDocumentLayout* documentLayout;
    QUrl* documentPath;
    QFileInfo* tabFileInfo;
    MarkdownHighlighter* highlighter;
    int defaultMathSize{10};

    void BaseSetup();

    bool GetDocumentModified() const { return _isModified; }
    void SetDocumentModified() { _isModified = true; }
    void SetDocumentModified(bool state) { _isModified = state; }

    bool GetIsAFile() const { return _isAFile; }
    void SetIsAFile(bool state) { _isAFile = state; }
    void SetFileLink(QString link) { _fileLink = link; }
    QUrl GetFileLink() const { return _fileLink; }

    void SetDocumentDir(QString dir){ _documentDir = dir; }
    QString GetDocumentDir() const { return _documentDir; }

    virtual void mouseDoubleClickEvent(QMouseEvent* mouseEvent) override;

public slots:
    void CheckForElements();

signals:
    void documentTextChanged(bool state);

protected:

private:
    QUrl _fileLink;// Keep track of the file to find the resoruces.
    QString _documentDir;
    bool _isAFile;    // Is the document already on disk as a file ?
    bool _isModified; // Was the file modified since the last save ?

    //Very simple element editor for TeX
    QPlainTextEdit* _elementEditor;;
};

#endif // NOTEEDITORTAB_H
