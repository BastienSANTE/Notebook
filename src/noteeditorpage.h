#ifndef NOTEEDITORPAGE_H
#define NOTEEDITORPAGE_H

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

class NoteEditorPage : public QWidget
{
public:
    Q_OBJECT

public:
    explicit NoteEditorPage(QWidget *parent = nullptr);
    explicit NoteEditorPage(QWidget* parent, QUrl fileName, QString contents);

    ~NoteEditorPage();
    QHBoxLayout* contentsLayout;
    QTextDocument* document;
    QTextDocument* renderDocument;
    QAbstractTextDocumentLayout* documentLayout;
    QUrl documentPath;

signals:
};

#endif // NOTEEDITORTAB_H
