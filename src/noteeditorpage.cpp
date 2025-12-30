#include "noteeditorpage.h"
#include "documentobjects/mathdocumentobject.h"

/* Class for the tabs in the editor.
 *
 */

NoteEditorPage::NoteEditorPage(QWidget *parent) {
    contentsLayout = new QHBoxLayout(this);
    document = new QTextDocument("Untitled", this);
    renderDocument = new QTextDocument(this);
    documentLayout = new QPlainTextDocumentLayout(document);

    //Register math elements
    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);
}

NoteEditorPage::NoteEditorPage(QWidget* parent, QUrl fileName, QString contents) {
    contentsLayout = new QHBoxLayout(this);
    document = new QTextDocument(contents, this);
    renderDocument = new QTextDocument(this);
    document->setBaseUrl(fileName);
    documentLayout = new QPlainTextDocumentLayout(document);

    qDebug() << document->baseUrl();

    //Register math elements
    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    document->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);
}


// Add method to prompt for save before deleting tab.
// Remember : Constructors & destructors are LIFO
NoteEditorPage::~NoteEditorPage() {};
