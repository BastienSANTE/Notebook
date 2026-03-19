#ifndef MARKDOWNTEXTEDIT_H
#define MARKDOWNTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QMouseEvent>
#include <QShortcut>
#include "markdownhighlighter.h"
#include "mainwindow.h"

class MarkdownTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MarkdownTextEdit(QWidget* parent);

    //MarkdownHighlighter* highlighter;
    QShortcut* H1Shortcut;
    QShortcut* H2Shortcut;
    QShortcut* H3Shortcut;
    QShortcut* InsertCodeShortcut;
    QShortcut* InsertListShortcut;

    QShortcut* InsertTableShortcut;
    QShortcut* RemoveRowShortcut;
    QShortcut* InsertRowShortcut;
    QShortcut* RemoveColumnShortcut;
    QShortcut* InsertColumnShortcut;


    virtual void mouseDoubleClickEvent(QMouseEvent* mouseEvent) override;


public slots:
    void InsertCode();
    void SetHeading(int level);
    void InsertList();
    void InsertTable();
    void InsertRow();
    void RemoveRow();
    void InsertColumn();
    void RemoveColumn();
};

#endif // MARKDOWNTEXTEDIT_H
