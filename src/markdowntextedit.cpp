#include "markdowntextedit.h"
#include <qtexttable.h>

MarkdownTextEdit::MarkdownTextEdit(QWidget* parent) {
    H1Shortcut = new QShortcut(QKeySequence("Ctrl+1"), this);
    H2Shortcut = new QShortcut(QKeySequence("Ctrl+2"), this);
    H3Shortcut = new QShortcut(QKeySequence("Ctrl+3"), this);
    InsertBlockShortcut = new QShortcut(QKeySequence("Ctrl+I"), this);
    InsertListShortcut = new QShortcut(QKeySequence("Ctrl+L"), this);
    InsertTableShortcut = new QShortcut(QKeySequence("Ctrl+T"), this);
    InsertRowShortcut = new QShortcut(QKeySequence("Ctrl+Shift+R"), this);
    RemoveRowShortcut = new QShortcut(QKeySequence("Ctrl+Alt+R"), this);
    InsertColumnShortcut = new QShortcut(QKeySequence("Ctrl+Shift+C"), this);
    RemoveColumnShortcut = new QShortcut(QKeySequence("Ctrl+Alt+C"), this);

    connect(H1Shortcut, &QShortcut::activated, [this]() {SetHeading(1); });
    connect(H2Shortcut, &QShortcut::activated, [this]() {SetHeading(2); });
    connect(H3Shortcut, &QShortcut::activated, [this]() {SetHeading(3); });
    connect(InsertListShortcut, &QShortcut::activated, this, &MarkdownTextEdit::InsertList);
    connect(InsertBlockShortcut, &QShortcut::activated, this, &MarkdownTextEdit::InsertCodeBlock);
    connect(InsertTableShortcut, &QShortcut::activated, this, &MarkdownTextEdit::InsertTable);
    connect(InsertRowShortcut, &QShortcut::activated, this, &MarkdownTextEdit::InsertRow);
    connect(RemoveRowShortcut, &QShortcut::activated, this, &MarkdownTextEdit::RemoveRow);
    connect(InsertColumnShortcut, &QShortcut::activated, this, &MarkdownTextEdit::InsertColumn);
    connect(RemoveColumnShortcut, &QShortcut::activated, this, &MarkdownTextEdit::RemoveColumn);

}

void MarkdownTextEdit::SetHeading(int level){

    QTextBlockFormat _fmt;
    _fmt.setHeadingLevel(level);

    textCursor().setBlockFormat(_fmt);
}

void MarkdownTextEdit::InsertList(){
    textCursor().insertList(QTextListFormat::ListSquare);
}

void MarkdownTextEdit::InsertCodeBlock(){

    if(textCursor().currentFrame() != document()->rootFrame()) return;
    QTextCursor cursor = this->textCursor();

    QTextFrameFormat codeBlockFmt;
    codeBlockFmt.setBackground(Qt::gray);

    cursor.insertFrame(codeBlockFmt);
}

void MarkdownTextEdit::InsertTable(){
    // Make it impossible to nest tables
    if (textCursor().currentFrame() != document()->rootFrame()){
        qDebug() << "Cannot nest tables (yet)";
        return;
    }

    textCursor().insertTable(1, 1);
}

void MarkdownTextEdit::InsertRow(){

    QTextTable* _tbl = textCursor().currentTable();

    if (!_tbl){ // Are we in a table ?
        qDebug() << "Cannot insert row outside of table";
        return;
    }

    _tbl->insertRows(_tbl->cellAt(textCursor().position()).row()+1, 1);
}

void MarkdownTextEdit::RemoveRow(){


    QTextTable* _tbl = textCursor().currentTable();

    if (!_tbl){ // Are we in a table ?
        qDebug() << "Cannot insert row outside of table";
        return;
    }

    _tbl->removeRows(_tbl->cellAt(textCursor().position()).row(), 1);
}

void MarkdownTextEdit::InsertColumn(){

    QTextTable* _tbl = textCursor().currentTable();

    if (!_tbl){ // Are we in a table ?
        qDebug() << "Cannot insert row outside of table";
        return;
    }

    _tbl->insertColumns(_tbl->cellAt(textCursor().position()).column()+1, 1);
}

void MarkdownTextEdit::RemoveColumn(){

    QTextTable* _tbl = textCursor().currentTable();

    if (!_tbl){ // Are we in a table ?
        qDebug() << "Cannot insert row outside of table";
        return;
    }

    _tbl->removeColumns(_tbl->cellAt(textCursor().position()).column(), 1);
}

void MarkdownTextEdit::mouseDoubleClickEvent(QMouseEvent* mouseEvent){
    /*QTextCursor cursor = cursorForPosition(mouseEvent->position().toPoint());
    cursor.select(QTextCursor::WordUnderCursor);

    const QTextCharFormat& _fmt = cursor.charFormat();

    if(_fmt.objectType() == MathDocumentObject::MathTextFormat){
        qDebug() << "Math Object encountered";
    }*/

    QTextCursor cursor = cursorForPosition(mouseEvent->position().toPoint());
    cursor.select(QTextCursor::BlockUnderCursor);

    const QTextFrame * _fmt = cursor.currentFrame();


    /*if(_fmt.objectType() == MathDocumentObject::MathTextFormat){
        qDebug() << "Math Object encountered";
        _elementEditor->setPlainText(_fmt.toolTip());
        _elementEditor->setVisible(true);
    }

    else {
        _elementEditor->setVisible(false);
    }*/

    qDebug() << _fmt->frameFormat().isTableFormat();
}


