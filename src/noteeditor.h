#ifndef NOTEEDITORFIXED_H
#define NOTEEDITORFIXED_H

#include <QObject>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QFile>
#include "noteeditortab.h"

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

    void AddTab();
    void CreateTabFromFile(QFile& fn);
    int UpdateCurrentTabIndex() const { return tabs->currentIndex(); }

    // Horrible nested methods IG, but let's see if this works
    NoteEditorTab* GetCurrentTab() const { return (NoteEditorTab*)tabs->currentWidget(); }
    QTextDocument* GetCurrentDocument() const {return GetCurrentTab()->document; }
    QString GetCurrentTabTitle() const { return tabs->tabText(tabs->currentIndex()); }

    void BaseSetup();
private:
    int _currentTabIndex;

signals:

public slots:
    void SwitchViews();
    void Save();
};

#endif // NOTEEDITORFIXED_H
