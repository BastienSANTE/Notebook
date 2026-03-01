#include "noteeditortab.h"
#include "documentobjects/mathdocumentobject.h"
#include <qregularexpression.h>


// If the document is untitled
NoteEditorTab::NoteEditorTab(QWidget *parent) {
    BaseSetup();
    document = new QTextDocument("Untitled", this);
    documentLayout = new QPlainTextDocumentLayout(document);

    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);

    _isAFile = false;
    _isModified = false;
    editor->setDocument(document);
}

// If created from a file
NoteEditorTab::NoteEditorTab(QWidget* parent, QString fileName, QString contents) {
    BaseSetup();

    //Set the current directory
    QFileInfo info(fileName);
    SetDocumentDir(info.absoluteDir().path());

    document = new QTextDocument(this);
    document->setMarkdown(contents);

    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);

    SetFileLink(fileName);
    document->setBaseUrl(fileName);

    _isAFile = true;
    _isModified = false;
    tabFileInfo = new QFileInfo(fileName);
    documentLayout = new QPlainTextDocumentLayout(document);
    editor->setDocument(document);
    highlighter = new MarkdownHighlighter(document);
}

void NoteEditorTab::BaseSetup(){
    tabContentsLayout = new QHBoxLayout(this);
    tabContentsLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(tabContentsLayout);
    editor = new MarkdownTextEdit(this);
    mdOutputViewer = new QPlainTextEdit(this);

    tabContentsLayout->addWidget(editor);
    tabContentsLayout->addWidget(mdOutputViewer);
    _elementEditor = new QPlainTextEdit(nullptr);
    _elementEditor->setVisible(false);

    connect(editor, &QTextEdit::textChanged, [this](){ SetDocumentModified(true); });
    connect(editor, &QTextEdit::textChanged, this, &NoteEditorTab::UpdateMDPreview);
}


void NoteEditorTab::UpdateMDPreview(){
    QString md = editor->toMarkdown();
    mdOutputViewer->setPlainText(md);
}

// Add method to prompt for save before deleting tab.
// Remember : Constructors & destructors are LIFO
NoteEditorTab::~NoteEditorTab() {};
