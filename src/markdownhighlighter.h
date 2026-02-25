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
    HighlightingRule mathRule;

    QTextCharFormat titleFormat;
    QTextCharFormat subtitleFormat;
    QTextCharFormat QuoteFormat;
    QTextCharFormat mathFormat;
    QTextCharFormat mathSourceFormat; // math source becomes "invisible" when matched

signals:
};

#endif // MARKDOWNHIGHLIGHTER_H
