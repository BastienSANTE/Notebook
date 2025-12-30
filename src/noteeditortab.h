#ifndef NOTEEDITORTAB_H
#define NOTEEDITORTAB_H

#include <QWidget>
#include <QUrl>
#include <QFileInfo>
#include <QStackedWidget>
#include <QPlainTextEdit>
#include "notebrowser.h"
#include <QBoxLayout>

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
    QStackedWidget* stackSwitcher;
    QHBoxLayout* tabContentsLayout;
    QTextEdit* editor;
    NoteBrowser* browser;
    QTextDocument* document;
    QTextDocument* renderDocument;
    QAbstractTextDocumentLayout* documentLayout;
    QUrl* documentPath;
    QFileInfo* tabFileInfo;

    int defaultMathSize{10};

    void BaseSetup();
    void ZoomRender();
    void UnzoomRender();
    void RenderDocument();

    bool GetDocumentModified() const { return _isModified; }
    void SetDocumentModified() { _isModified = true; }
    void SetDocumentModified(bool state) { _isModified = state; }

    bool GetIsAFile() const { return _isAFile; }
    void SetIsAFile(bool state) { _isAFile = state; }
    void SetFileLink(QString link) { _fileLink = link; }
    QUrl GetFileLink() const { return _fileLink; }

signals:
    void documentTextChanged(bool state);

protected:

private:
    QUrl _fileLink;// Keep track of the file to find the resoruces.
    bool _isAFile;    // Is the document already on disk as a file ?
    bool _isModified; // Was the file modified since the last save ?
};

#endif // NOTEEDITORTAB_H
