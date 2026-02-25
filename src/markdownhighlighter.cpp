#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter{parent}
{
    HighlightingRule titleRule;
    titleFormat.setFontPointSize(20);
    titleRule.pattern = QRegularExpression(QStringLiteral("^#[^#].*"));
    titleRule.format = titleFormat;
    highlightingRules.append(titleRule);

    HighlightingRule quoteRule;
    quoteRule.pattern = QRegularExpression(QStringLiteral("^[>].*"));
    QuoteFormat.setForeground(Qt::blue);
    quoteRule.format = QuoteFormat;
    highlightingRules.append(quoteRule);

    mathSourceFormat.setForeground(Qt::blue);
    //mathFormat = MathDocumentObject::GenerateFormat(&mathRenderText);
    mathRule.pattern = QRegularExpression(QStringLiteral("(?=\\${2}).+(?>\\${2})"));
    mathRule.format = mathSourceFormat;
}


void MarkdownHighlighter::highlightBlock(const QString& text){

    for(const HighlightingRule& rule:std::as_const(highlightingRules)){
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            qDebug() << "Matched " << match.captured() << " ";
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    QRegularExpressionMatchIterator mathMatchIterator = mathRule.pattern.globalMatch(text);
    while(mathMatchIterator.hasNext()){
        QRegularExpressionMatch mathMatch = mathMatchIterator.next();


        QTextCursor cursor(QSyntaxHighlighter::currentBlock());

        cursor.setPosition(QSyntaxHighlighter::currentBlock().position() + mathMatch.capturedStart(), QTextCursor::MoveAnchor);
        cursor.setPosition(cursor.position() + mathMatch.capturedLength(), QTextCursor::KeepAnchor);
        //cursor.select(QTextCursor::WordUnderCursor);

        cursor.removeSelectedText();
        std::wstring renderText = mathMatch.captured().toStdWString();
        render = tex::LaTeX::parse(renderText,
                                   0, 12, 14 / 3.f, 0xff424242);

        cursor.insertText(QString(QChar::ObjectReplacementCharacter), MathDocumentObject::GenerateFormat(
                                                                        render, render->getWidth(),
                                                                        render->getHeight(),
                                                                        renderText));
    }
}
