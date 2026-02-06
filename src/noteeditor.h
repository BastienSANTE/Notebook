#ifndef NOTEEDITORFIXED_H
#define NOTEEDITORFIXED_H

#include <QObject>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileSystemModel>
#include <QTreeView>
#include <QSplitter>
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
    QTabWidget* tabs;           // Container for the editor & viewer


    QFileSystemModel* fsModel;
    QTreeView* tree;
    QSplitter* splitter;

    QTextDocument* currentDocument; //document currently open
    QRegularExpression* latexRE;

    QString baseDirectory;

    // Menus & Actions
    QMenu* fileMenu;
    QAction * openFileAction;

    void AddTab();
    void CreateTabFromFile(QFile& fn);
    void RemoveCurrentTab();
    void OpenFile();
    void OpenFile(QModelIndex idx);
    int UpdateCurrentTabIndex() const { return tabs->currentIndex(); }
    void SetTabTitle(QString title);

    // Horrible nested methods IG, but let's see if this works
    NoteEditorTab* GetCurrentTab() const { return (NoteEditorTab*)tabs->currentWidget(); }
    QString GetCurrentTabTitle() const { return tabs->tabText(tabs->currentIndex()); }

    void BaseSetup();

    void FollowLink(const QUrl& followedFile);

private:
    int _currentTabIndex;
    QShortcut* saveShortcut;
    QShortcut* addTabShortcut;
    QShortcut* removeTabShortcut;

signals:

public slots:
    void Save();
};

#endif // NOTEEDITORFIXED_H
