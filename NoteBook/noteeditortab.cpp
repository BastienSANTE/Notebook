#include "noteeditortab.h"

/* Class for the tabs in the editor.
 *
 */

NoteEditorTab::NoteEditorTab(QWidget *parent) : QWidget{parent} {
    stackSwitcher = new QStackedWidget(this);
    editor = new QPlainTextEdit(this);
    browser = new QTextBrowser(this);
    document = new QTextDocument("Untitled", this);

    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);
    editor->setDocument(document);
    browser->setDocument(document);
}

NoteEditorTab::NoteEditorTab(QWidget* parent, QString contents) {
    stackSwitcher = new QStackedWidget(this);
    editor = new QPlainTextEdit(this);
    browser = new QTextBrowser(this);
    document = new QTextDocument(contents, this);

    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    editor->setDocument(document);
    browser->setDocument(document);
    //editor->setPlainText(contents);
}

NoteEditorTab::~NoteEditorTab() {};
