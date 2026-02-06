#include "markdowntextedit.h"

MarkdownTextEdit::MarkdownTextEdit(QWidget* parent) {}

void MarkdownTextEdit::mouseDoubleClickEvent(QMouseEvent* mouseEvent){
    QTextCursor cursor = cursorForPosition(mouseEvent->position().toPoint());
    cursor.select(QTextCursor::WordUnderCursor);

    const QTextCharFormat& _fmt = cursor.charFormat();

    if(_fmt.objectType() == MathDocumentObject::MathTextFormat){
        qDebug() << "Math Object encountered";
    }
}
