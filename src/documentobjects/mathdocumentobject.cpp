#include "mathdocumentobject.h"

MathDocumentObject::MathDocumentObject(QObject* parent) : QObject(parent) {

}

QSizeF MathDocumentObject::intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat& format){

    // I don't get what this line does yet (cast the contents ???)
    QImage image = qvariant_cast<QImage>(format.property(PicturePropertyId));
    QSizeF imageSize = image.size();
    return imageSize;

}

void MathDocumentObject::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    QImage image = qvariant_cast<QImage>(format.property(PicturePropertyId));

    if (image.isNull()) return;

    QSize displaySize = image.rect().size();
    painter->save();
    painter->setClipRect(rect);
    painter->drawImage(rect.topLeft(), image);
    painter->restore();
}

static QTextCharFormat GenerateFormat(JKQTMathText* text, int width = 0, int height = 0) {

    QImage textImage;
    QPainter textPainter;
    textPainter.begin(&textImage);
    textImage = text->drawIntoImage(false, Qt::white, 0, 1.0, 96);
    textPainter.end();

    QTextCharFormat format;
    format.setObjectType(MathDocumentObject::MathTextFormat);
    format.setProperty(MathDocumentObject::PicturePropertyId, QVariant::fromValue(textImage));
    return format;
}
