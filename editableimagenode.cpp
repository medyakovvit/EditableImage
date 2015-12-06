#include "editableimagenode.h"
#include <QSGFlatColorMaterial>

EditableImageNode::EditableImageNode(const QImage &img, QQuickWindow *window) :
    mGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 4),
    pTexture(NULL),
    pWindow(window)
{
    setGeometry(&mGeometry);

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial();
    material->setColor(QColor(0,0,0));
    material->setFlag(QSGMaterial::Blending);
    setMaterial(material);
    setFlag(OwnsMaterial);

    QSGSimpleTextureNode *node = setTexture(img, window);
    if(node)
        appendChildNode(node);
}

EditableImageNode::~EditableImageNode()
{
    delete pTexture;
}

void EditableImageNode::setImage(const QImage &img)
{
    delete pTexture;
    setTexture(img, pWindow);
}

QSGSimpleTextureNode *EditableImageNode::setTexture(const QImage &img, QQuickWindow *window)
{
    QSGSimpleTextureNode *node = static_cast<QSGSimpleTextureNode *>(this->firstChild());
    if(!node)
        node = new QSGSimpleTextureNode();

    pTexture = window->createTextureFromImage(img);
    node->setTexture(pTexture);
    node->setRect(0, 0, img.width(), img.height());
    node->setFiltering(QSGTexture::Linear);
    return node;
}

