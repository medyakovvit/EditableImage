#include "editableimage.h"
#include "editableimagenode.h"

EditableImage::EditableImage(QQuickItem *parent) : QQuickItem(parent)
{
    setFlag(ItemHasContents);

    connect(this, &EditableImage::imageChanged, &EditableImage::needUpdate);
    connect(this, &EditableImage::rChanged, &EditableImage::needUpdate);
    connect(this, &EditableImage::gChanged, &EditableImage::needUpdate);
    connect(this, &EditableImage::bChanged, &EditableImage::needUpdate);
}

void EditableImage::setImage(const QImage& img)
{
    if(mImage == img)
        return;

    mImage = img;
    emit imageChanged(mImage);
}

void EditableImage::setR(int r)
{
    if (mR == r)
        return;

    mR = r;
    emit rChanged(r);
}

void EditableImage::setG(int g)
{
    if (mG == g)
        return;

    mG = g;
    emit gChanged(g);
}

void EditableImage::setB(int b)
{
    if (mB == b)
        return;

    mB = b;
    emit bChanged(b);
}

void EditableImage::load(const QString &fileName)
{
    if (!QFile::exists(fileName))
        return;

    mImage.load(fileName);
    setR(0.0);
    setG(0.0);
    setB(0.0);
    emit imageChanged(mImage);
}

QSGNode *EditableImage::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    EditableImageNode* node = static_cast<EditableImageNode *>(oldNode);

    if(mImage.isNull())
        return node;

    QImage img;

    if (mR == 0 && mG == 0 && mB == 0)
        img = mImage.scaled(width(), height());
    else
        img = addToPixels(mR, mG, mB).scaled(width(), height());

    if (!node)
        node = new EditableImageNode(img, window());
    else
        node->setImage(img);

    return node;
}

QImage EditableImage::addToPixels(int r, int g, int b)
{
    QImage img(mImage);
    for(int i=0; i<img.height(); i++)
        for(int j=0; j<img.width(); j++)
        {
            QRgb oldRgb = img.pixel(j, i);
            img.setPixel(j, i, qRgb(qRed(oldRgb) + r,
                                  qGreen(oldRgb) + g,
                                   qBlue(oldRgb) + b));
        }
    return img;
}

