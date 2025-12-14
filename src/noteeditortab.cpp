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
    documentLayout = new QPlainTextDocumentLayout(document);

    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    editor->setDocument(document);
    browser->setDocument(document);
}

NoteEditorTab::NoteEditorTab(QWidget* parent, QUrl fileName, QString contents) {
    stackSwitcher = new QStackedWidget(this);
    tabContentsLayout = new QHBoxLayout(this);
    this->setLayout(tabContentsLayout);
    tabContentsLayout->addWidget(stackSwitcher);

    editor = new QPlainTextEdit(this);
    browser = new QTextBrowser(this);
    document = new QTextDocument(contents, this);
    document->setBaseUrl(fileName);
    documentLayout = new QPlainTextDocumentLayout(document);
    //document->addResource(QTextDocument::StyleSheetResource, QUrl("/home/bastien/LocalRepo/Notebook/NoteBook/TestFolder/TestStyleSheet.css"), css);

    qDebug() << document->baseUrl();

    //stackSwitcher->setLayout(tabLayout);
    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    browser->setSource(fileName, QTextDocument::MarkdownResource);
    editor->setPlainText(document->toPlainText());

    editor->setDocument(document);
}


// Add method to prompt for save before deleting tab.
// Remember : Constructors & destructors are LIFO
NoteEditorTab::~NoteEditorTab() {};
