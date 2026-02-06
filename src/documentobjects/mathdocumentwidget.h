#ifndef MATHDOCUMENTWIDGET_H
#define MATHDOCUMENTWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include "samples/qt_texwidget.h"

class MathDocumentWidget : public QWidget, public QTextObjectInterface
{
public:

    TeXWidget* texWidget;
    QPlainTextEdit * texEdit;

    MathDocumentWidget();

};

#endif // MATHDOCUMENTWIDGET_H
