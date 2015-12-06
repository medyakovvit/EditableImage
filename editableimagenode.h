#ifndef EDITABLEIMAGENODE_H
#define EDITABLEIMAGENODE_H

#include <QObject>
#include <QSGGeometryNode>
#include <QQuickWindow>
#include <QSGTexture>
#include <QSGSimpleTextureNode>
#include <QSGGeometry>

class EditableImageNode : public QSGGeometryNode
{
public:
    EditableImageNode(const QImage &img, QQuickWindow *window);
    ~EditableImageNode();

    void setImage(const QImage& img);

protected:
    QSGSimpleTextureNode* setTexture(const QImage &img, QQuickWindow *window);

private:
    QImage mImage;
    QSGGeometry mGeometry;
    QSGTexture *pTexture;
    QQuickWindow *pWindow;
};

#endif // EDITABLEIMAGENODE_H
