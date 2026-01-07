#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class MarkdownHighlighter : public QSyntaxHighlighter
{
public:
    explicit MarkdownHighlighter(QObject *parent = nullptr);

    void highlightBlock(const QString &text);

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    }

    QList<HighlightingRule> highlightingRules;

signals:
};

#endif // MARKDOWNHIGHLIGHTER_H
