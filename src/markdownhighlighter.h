#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QList>
#include <jkqtmathtext.h>
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

    JKQTMathText mathRenderText;

    QList<HighlightingRule> highlightingRules;

    QTextCharFormat titleFormat;
    QTextCharFormat subtitleFormat;
    QTextCharFormat mathFormat;

signals:
};

#endif // MARKDOWNHIGHLIGHTER_H
