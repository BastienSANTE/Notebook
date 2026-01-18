#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter{parent}
{
    HighlightingRule titleRule;

    titleFormat.setFontPointSize(20);
    titleRule.pattern = QRegularExpression(QStringLiteral("^#[^#].*"));
    titleRule.format = titleFormat;
    highlightingRules.append(titleRule);


    mathSourceFormat.setForeground(Qt::blue);
    //mathFormat = MathDocumentObject::GenerateFormat(&mathRenderText);
    mathRule.pattern = QRegularExpression(QStringLiteral("(?=\\${2}).+(?>\\${2})"));
    mathRule.format = mathSourceFormat;
    //highlightingRules.append(mathRule);
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
        qDebug() << "Matched " << mathMatch.captured() << " ";

        QTextCursor cursor(QSyntaxHighlighter::currentBlock());

        cursor.setPosition(QSyntaxHighlighter::currentBlock().position() + mathMatch.capturedStart());

        cursor.deletePreviousChar();
        render = tex::LaTeX::parse(mathMatch.captured().toStdWString(),
                                   0, 20, 20 / 3.f, 0xff424242);

        setFormat(mathMatch.capturedStart(), mathMatch.capturedLength(), MathDocumentObject::GenerateFormat(render, render->getWidth(), render->getHeight()));
        cursor.insertText(QString(QChar::ObjectReplacementCharacter), MathDocumentObject::GenerateFormat(render, render->getWidth(), render->getHeight()));

    }
}
