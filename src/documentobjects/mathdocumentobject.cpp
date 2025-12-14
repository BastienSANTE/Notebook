#include "mathdocumentobject.h"

MathDocumentObject::MathDocumentObject(QObject* parent) {}

QSizeF MathDocumentObject::intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat& format){

    JKQTMathText mathText;
    QImage image = mathText.drawIntoImage(false, Qt::white, 0, 1.0, 96);
    QSizeF imageSize = image.size();
    return imageSize;

}

void MathDocumentObject::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    JKQTMathText mathText;
    QImage image = mathText.drawIntoImage(false, Qt::white, 0, 1.0, 96);
    painter->drawImage(image.rect(), image);
}

