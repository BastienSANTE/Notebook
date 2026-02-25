#include "noteeditortab.h"
#include "documentobjects/mathdocumentobject.h"
#include <qregularexpression.h>

/* Class for the tabs in the editor.
 *
 */

NoteEditorTab::NoteEditorTab(QWidget *parent) {
    BaseSetup();
    document = new QTextDocument("Untitled", this);
    documentLayout = new QPlainTextDocumentLayout(document);

    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);

    _isAFile = false;
    _isModified = false;
    editor->setDocument(document);
    highlighter = new MarkdownHighlighter(document);
}

NoteEditorTab::NoteEditorTab(QWidget* parent, QString fileName, QString contents) {
    BaseSetup();

    //Set the current directory
    QFileInfo info(fileName);
    SetDocumentDir(info.absoluteDir().path());

    document = new QTextDocument(QString(contents), this);

    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);

    SetFileLink(fileName);
    renderDocument->setBaseUrl(fileName);
    document->setBaseUrl(fileName);
    qDebug() << renderDocument->baseUrl();

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

    renderDocument = new QTextDocument(this);
    renderDocument->setDocumentMargin(20);
    tabContentsLayout->addWidget(editor);

    _elementEditor = new QPlainTextEdit(nullptr);
    _elementEditor->setVisible(false);

    connect(editor, &QTextEdit::textChanged, [this](){ SetDocumentModified(true); });
}


void NoteEditorTab::CheckForElements(){
    const QTextCharFormat& _fmt = editor->textCursor().charFormat();

    if(_fmt.objectType() == MathDocumentObject::MathTextFormat){
        qDebug() << "Math Object encountered";
        _elementEditor->setPlainText(_fmt.toolTip());
        _elementEditor->setVisible(true);
    }

    else {
        _elementEditor->setVisible(false);
    }
}

void NoteEditorTab::mouseDoubleClickEvent(QMouseEvent* mouseEvent){
    QTextCursor cursor = editor->cursorForPosition(mouseEvent->position().toPoint());
    cursor.select(QTextCursor::WordUnderCursor);

    const QTextCharFormat& _fmt = cursor.charFormat();

    if(_fmt.objectType() == MathDocumentObject::MathTextFormat){
        qDebug() << "Math Object encountered";
        _elementEditor->setPlainText(_fmt.toolTip());
        _elementEditor->setVisible(true);
    }

    else {
        _elementEditor->setVisible(false);
    }
}

// Add method to prompt for save before deleting tab.
// Remember : Constructors & destructors are LIFO
NoteEditorTab::~NoteEditorTab() {};
