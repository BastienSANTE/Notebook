#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QList>
#include "samples/qt_texwidget.h"
#include "documentobjects/mathdocumentobject.h"

class MarkdownHighlighter : public QSyntaxHighlighter
{
public:
    explicit MarkdownHighlighter(QTextDocument* parent = nullptr);

    void highlightBlock(const QString &text);

private:

    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    tex::TeXRender* render;

    QList<HighlightingRule> highlightingRules;
    HighlightingRule    H1Rule, H2Rule, H3Rule, H4Rule, H5Rule, H6Rule;
    QTextCharFormat     H1Fmt, H2Fmt, H3Fmt, H4Fmt, H5Fmt, H6Fmt;

    HighlightingRule    horizontalLineRule;
    QTextCharFormat     horizontalLineFmt;

    HighlightingRule    orderedListRule;
    QTextCharFormat     orderedListFmt;

    HighlightingRule    mathRule;
    QTextCharFormat     mathFormat;

    HighlightingRule    inlineCodeRule;
    QTextCharFormat     inlineCodeFmt;

    HighlightingRule    codeBlockRule;
    QTextCharFormat     codeBlockTextFmt;
    QTextFrameFormat    codeBlockFrameFmt;

    QTextCharFormat QuoteFormat;

    enum highlightingStates {
        NoState,
        CodeBlock
    };

    void InitRulesAndFormats();

    void HighlightHeadings(const QString& text);
    QString TEST_FormatInlineCode(QString text);

signals:
};

#endif // MARKDOWNHIGHLIGHTER_H
