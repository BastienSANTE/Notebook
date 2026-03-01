#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter{parent}
{

    InitRulesAndFormats();

    mathSourceFormat.setForeground(Qt::blue);
    mathRule.pattern = QRegularExpression(QStringLiteral("(?=\\${2}).+(?>\\${2})"));
    mathRule.format = mathSourceFormat;
}

/* This functions handles all main formats, such as titles,
 * lists, etc.*/
void MarkdownHighlighter::InitRulesAndFormats(){
    H1Rule.pattern = QRegularExpression(QStringLiteral("^#[^#].*"));
    H1Fmt.setFontPointSize(20);
    H1Rule.format = H1Fmt;
    highlightingRules.append(H1Rule);

    H2Rule.pattern = QRegularExpression(QStringLiteral("^##[^#].*"));
    H2Fmt.setFontPointSize(18);
    H2Rule.format = H2Fmt;
    highlightingRules.append(H2Rule);

    H3Rule.pattern = QRegularExpression(QStringLiteral("^###[^#].*"));
    H3Fmt.setFontPointSize(16);
    H3Rule.format = H3Fmt;
    highlightingRules.append(H3Rule);

    // TODO : Go until H6

    // Horizontal Lines
    horizontalLineRule.pattern = QRegularExpression(QStringLiteral("^(- ){3}"));

    // Lists
    orderedListRule.pattern = QRegularExpression(QStringLiteral("^[\\s]*\\*.+"));
    orderedListFmt.setBackground(Qt::red);
    orderedListRule.format = orderedListFmt;
    highlightingRules.append(orderedListRule);

    // Inline Code
    inlineCodeRule.pattern = QRegularExpression(QStringLiteral("`[^`]+`"));
    inlineCodeFmt.setBackground(Qt::gray);
    inlineCodeRule.format = inlineCodeFmt;
    highlightingRules.append(inlineCodeRule);

    // Code Blocks
    codeBlockRule.pattern = QRegularExpression(QStringLiteral("^[`]{3}"));
    codeBlockFrameFmt.setBackground(Qt::gray);
    codeBlockFrameFmt.setPadding(5);
}


void MarkdownHighlighter::highlightBlock(const QString& text){

    if(currentBlock().blockFormat().headingLevel() >= 0){
        HighlightHeadings(text);
    }

    /*for(const HighlightingRule& rule:std::as_const(highlightingRules)){
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            qDebug() << "Matched " << match.captured();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }*/

    /*Beyond this point, we handle the replacement of certain elements
     with others, such as lists with proper QTextLists*/

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


void MarkdownHighlighter::HighlightHeadings(const QString& text){

    switch(currentBlock().blockFormat().headingLevel()){
        case 1:
            setFormat(0, text.length(), H1Fmt);
            break;
        case 2:
            setFormat(0, text.length(), H2Fmt);
            break;
        case 3:
            setFormat(0, text.length(), H3Fmt);
            break;
    }
}
