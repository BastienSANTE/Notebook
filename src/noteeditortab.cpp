#include "noteeditortab.h"
#include "documentobjects/mathdocumentobject.h"
#include <qregularexpression.h>

/* Class for the tabs in the editor.
 *
 */

NoteEditorTab::NoteEditorTab(QWidget *parent) {
    BaseSetup();
    document = new QTextDocument("Untitled", this);
    document->setDefaultFont(QFont("Courier", 12));
    documentLayout = new QPlainTextDocumentLayout(document);
    _isAFile = false;
    _isModified = false;
    editor->setDocument(document);
    browser->setDocument(renderDocument);
}

NoteEditorTab::NoteEditorTab(QWidget* parent, QString fileName, QString contents) {
    BaseSetup();

    //Set the current directory
    QFileInfo info(fileName);
    SetDocumentDir(info.absoluteDir().path());

    document = new QTextDocument(QString(contents), this);
    document->setDefaultFont(QFont("Courier", 10));     // TODO : Make a font menu

    SetFileLink(fileName);
    renderDocument->setBaseUrl(fileName);
    document->setBaseUrl(fileName);
    qDebug() << renderDocument->baseUrl();

    _isAFile = true;
    _isModified = false;
    tabFileInfo = new QFileInfo(fileName);
    documentLayout = new QPlainTextDocumentLayout(document);
    editor->setDocument(document);
    browser->setDocument(renderDocument);
}

void NoteEditorTab::BaseSetup(){
    stackSwitcher = new QStackedWidget(this);
    tabContentsLayout = new QHBoxLayout(this);
    tabContentsLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(tabContentsLayout);
    tabContentsLayout->addWidget(stackSwitcher);
    editor = new QTextEdit(this);
    browser = new NoteBrowser(this);

    renderDocument = new QTextDocument(this);
    renderDocument->setDocumentMargin(20);
    stackSwitcher->addWidget(editor);
    stackSwitcher->addWidget(browser);

    //Register math elements
    MathDocumentObject* mathDocumentObjectHandler = new MathDocumentObject(this);
    renderDocument->documentLayout()->registerHandler(MathDocumentObject::MathTextFormat, mathDocumentObjectHandler);

    connect(browser, &NoteBrowser::zoomFactorIncreased, this, &NoteEditorTab::ZoomRender);
    connect(browser, &NoteBrowser::zoomFactorDecreased, this, &NoteEditorTab::UnzoomRender);
    connect(editor, &QTextEdit::textChanged, [this](){ SetDocumentModified(true); });
}



void NoteEditorTab::RenderDocument(){
    // Clear text doc before new render
    renderDocument->clear();

    // Render the basic elements as Markdown
    renderDocument->setMarkdown(editor->toPlainText(), QTextDocument::MarkdownDialectGitHub);

    // Get all of the text as one large QString
    QString documentText = renderDocument->toPlainText();

    QTextCursor cursor(renderDocument);
    JKQTMathText* mathRender = new JKQTMathText(this);
    mathRender->setFontSize(defaultMathSize);

    bool _lastParseResult = true;

    while(_lastParseResult) {
        cursor = renderDocument->find(QRegularExpression("(?=\\${2}).*(?<=\\${2})"), cursor);
        QString matchText = cursor.selectedText();

        if (matchText == "") {
            _lastParseResult = false;
        }

        cursor.removeSelectedText();

        if (mathRender->parse(matchText)) {
            cursor.insertText(QString(QChar::ObjectReplacementCharacter), MathDocumentObject::GenerateFormat(mathRender));
        }
    }

    delete (mathRender);
}

void NoteEditorTab::ZoomRender(){
    defaultMathSize++;
    qDebug() << defaultMathSize;
    RenderDocument();
}

void NoteEditorTab::UnzoomRender(){
    if(defaultMathSize < 2) return;
    defaultMathSize--;
    qDebug() << defaultMathSize;
    RenderDocument();
}

// Add method to prompt for save before deleting tab.
// Remember : Constructors & destructors are LIFO
NoteEditorTab::~NoteEditorTab() {};
