#ifndef NOTEEDITORFIXED_H
#define NOTEEDITORFIXED_H

#include <QObject>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QFile>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QRegularExpression>
#include <QShortcut>
#include <QMessageBox>
#include "noteeditortab.h"
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
    QHBoxLayout* tabBox;        // Layout
    QHBoxLayout* buttonBox;     // Buttons holder
    QTabWidget* tabs;           // Container for the editor & viewer

    QPushButton* switchBtn;     // View switcher button
    QPushButton* saveBtn;       // Save file button
    QPushButton* addTabBtn;     // Add new tab (and create new file)
    QPushButton* deleteTabBtn;  // Delete tab and document IF EMPTY, else prompt save

    QTextDocument* currentDocument; //document currently open
    QRegularExpression* latexRE;

    // Menus & Actions
    QMenu* fileMenu;
    QAction * openFileAction;

    void AddTab();
    void CreateTabFromFile(QFile& fn);
    void RemoveCurrentTab();
    void OpenFile();
    int UpdateCurrentTabIndex() const { return tabs->currentIndex(); }
    void SetTabTitle(QString title);

    // Horrible nested methods IG, but let's see if this works
    NoteEditorTab* GetCurrentTab() const { return (NoteEditorTab*)tabs->currentWidget(); }
    QTextDocument* GetCurrentDocument() const {return GetCurrentTab()->document; }
    QString GetCurrentTabTitle() const { return tabs->tabText(tabs->currentIndex()); }
    void RenderDocument(QTextDocument* doc);

    void BaseSetup();

private:
    int _currentTabIndex;
    QShortcut* switchShortcut;

signals:

public slots:
    void SwitchViews();
    void Save();
    void SaveAs();
};

#endif // NOTEEDITORFIXED_H
