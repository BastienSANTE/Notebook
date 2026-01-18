#include "mathdocumentobject.h"

MathDocumentObject::MathDocumentObject(QObject* parent) : QObject(parent) {

}

QSizeF MathDocumentObject::intrinsicSize(QTextDocument* doc, int posInDocument, const QTextFormat& format){

    Q_UNUSED(doc); Q_UNUSED(posInDocument);
    // I don't get what this line does yet (cast the contents ???)
    QImage pic = qvariant_cast<QImage>(format.property(PicturePropertyId));
    QSizeF imageSize = pic.size();
    return imageSize;

}

void MathDocumentObject::drawObject(QPainter *painter, const QRectF &rect, QTextDocument *doc, int posInDocument, const QTextFormat &format) {
    QImage pic = qvariant_cast<QImage>(format.property(PicturePropertyId));

    if (pic.isNull()){
        qDebug() << "Image is null";
        return;
    }

    QSize displaySize = pic.size();
    displaySize.scale(rect.size().toSize(), Qt::KeepAspectRatio);
    double scaleFactor = displaySize.width()/(double)pic.size().width();
    painter->save();
    painter->scale(scaleFactor, scaleFactor);
    painter->setClipRect(rect);
    painter->drawImage(rect.topLeft(), pic);
    painter->restore();
}

QTextCharFormat MathDocumentObject::GenerateFormat(tex::TeXRender* render, int width, int height) {

    qDebug() << render->getWidth() << "x" << render->getHeight();

    QImage _pxm(width, height, QImage::Format_ARGB32);
    _pxm.fill(Qt::white);

    QPainter textPainter;
    textPainter.begin(&_pxm);
    textPainter.setRenderHint(QPainter::Antialiasing, true);
    tex::Graphics2D_qt g2(&textPainter);
    render->draw(g2, 0, 0);
    textPainter.end();

    //QPicture textImage = _pxm.();

    QTextCharFormat format;
    format.setObjectType(MathDocumentObject::MathTextFormat);
    format.setProperty(MathDocumentObject::PicturePropertyId, QVariant::fromValue(_pxm));
    return format;
}
