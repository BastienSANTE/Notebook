#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter{parent}
{
    HighlightingRule titleRule;

    titleFormat.setFontPointSize(20);
    titleRule.pattern = QRegularExpression(QStringLiteral("^#[^#].*"));
    titleRule.format = titleFormat;
    highlightingRules.append(titleRule);

    HighlightingRule mathRule;
    mathFormat = MathDocumentObject::GenerateFormat(&mathRenderText);
    mathRule.pattern = QRegularExpression("(?=\\${2}).*(?<=\\${2})");
    mathRule.format = mathFormat;
    highlightingRules.append(mathRule);

}


void MarkdownHighlighter::highlightBlock(const QString& text){

    for(const HighlightingRule& rule:std::as_const(highlightingRules)){
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            qDebug() << "Matched " << match.captured() << " ";
            setFormat(match.capturedStart(), match.capturedEnd(), rule.format);
        }
    }
}
