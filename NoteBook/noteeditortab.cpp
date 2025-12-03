#include "noteeditortab.h"

/* Class for the tabs in the editor.
 *
 */

NoteEditorTab::NoteEditorTab(QWidget *parent) {
    stackSwitcher = new QStackedWidget(this);
    tabContentsLayout = new QHBoxLayout(this);
    this->setLayout(tabContentsLayout);
    tabContentsLayout->addWidget(stackSwitcher);

    editor = new QPlainTextEdit(this);
    browser = new QTextBrowser(this);
    document = new QTextDocument("Untitled", this);

    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    editor->setDocument(document);
    browser->setDocument(document);
}

NoteEditorTab::NoteEditorTab(QWidget* parent, QString contents) {
    stackSwitcher = new QStackedWidget(parent);
    editor = new QPlainTextEdit(this);
    browser = new QTextBrowser(this);
    document = new QTextDocument(contents, this);
    //tabLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    //stackSwitcher->setLayout(tabLayout);
    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    editor->setDocument(document);
    browser->setDocument(document);
    //editor->setPlainText(contents);
}

NoteEditorTab::~NoteEditorTab() {};
