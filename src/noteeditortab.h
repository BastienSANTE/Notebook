#ifndef NOTEEDITORTAB_H
#define NOTEEDITORTAB_H

#include <QWidget>
#include <QUrl>
#include <QStackedWidget>
#include <QPlainTextEdit>
#include <QTextBrowser>
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
    explicit NoteEditorTab(QWidget* parent, QUrl fileName, QString contents);

    ~NoteEditorTab();
    QStackedWidget* stackSwitcher;
    QHBoxLayout* tabContentsLayout;
    QPlainTextEdit* editor;
    QTextBrowser* browser;
    QTextDocument* document;
    QAbstractTextDocumentLayout* documentLayout;
    QUrl* documentPath;

signals:
};

#endif // NOTEEDITORTAB_H
