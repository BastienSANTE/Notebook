#ifndef NOTEEDITORFIXED_H
#define NOTEEDITORFIXED_H

#include <QObject>
#include <QBoxLayout>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextEdit>
#include <QTextBrowser>
#include <QFile>
#include <QFileDialog>
#include <QRegularExpression>
#include <QShortcut>
#include "noteeditorpage.h"
#include "notebrowser.h"
#include "documentobjects/mathdocumentobject.h"

class Editor : public QObject
{
    Q_OBJECT

public:
    explicit Editor(QString fn);
    explicit Editor();

    QMainWindow* mainWindow;    // Main Window of the editor,
    QFrame* uiFrame;            // is the parent of the whole UI
    QVBoxLayout* layout;        // Application layout
    QHBoxLayout* buttonBox;     // Buttons holder
    QHBoxLayout* stackLayout;

    // Menus & Actions
    QMenu* fileMenu;
    QAction * openFileAction;

    QTextEdit* editor;
    NoteBrowser* browser;
    QStackedWidget* stackSwitcher;

    QPushButton* switchBtn;     // View switcher button
    QPushButton* saveBtn;       // Save file button
    QPushButton* addPageBtn;     // Add new tab (and create new file)
    QPushButton* closePageBtn;  // Delete tab and document IF EMPTY, else prompt save

    QRegularExpression* latexRE;

    void OpenFile();
    void CreateEmptyPage();
    void CreatePageFromFile(QFile& fn);

    void RenderDocument(QTextDocument* doc);

    void BaseSetup();
    void SetupMathDocumentObject();
    NoteEditorPage* GetCurrentPage() const { return _currentPage; }
    void SetCurrentPage(NoteEditorPage* page) { _currentPage = page; }

private:
    int _currentTabIndex;
    NoteEditorPage* _currentPage;
    QShortcut* switchShortcut;

signals:

public slots:
    void SwitchViews();
    void Save();
};

#endif // NOTEEDITORFIXED_H
