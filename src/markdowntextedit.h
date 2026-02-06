#ifndef MARKDOWNTEXTEDIT_H
#define MARKDOWNTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QMouseEvent>
#include "markdownhighlighter.h"

class MarkdownTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MarkdownTextEdit(QWidget* parent);

    virtual void mouseDoubleClickEvent(QMouseEvent* mouseEvent) override;

};

#endif // MARKDOWNTEXTEDIT_H
