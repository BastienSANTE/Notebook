#ifndef MATHDOCUMENTOBJECT_H
#define MATHDOCUMENTOBJECT_H

#include <QObject>
#include <QAbstractTextDocumentLayout>
#include <QSize>
#include <jkqtmathtext.h>

/*This class allows insertion of math objects inside documents,
 only equations for the moment */

class MathDocumentObject : public QObject, public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

public:
    enum {MathTextFormat = QTextFormat::UserFormat + 1};
    enum {PicturePropertyId = 1};

    explicit MathDocumentObject(QObject* parent);
    QSizeF intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat& format);
    void drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) override;
};

#endif // MATHDOCUMENTOBJECT_H
