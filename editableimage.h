#ifndef EDITABLEIMAGE_H
#define EDITABLEIMAGE_H

#include <QObject>
#include <QtQuick/QQuickItem>
#include <QImage>

class EditableImage : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(int r READ r WRITE setR NOTIFY rChanged)
    Q_PROPERTY(int g READ g WRITE setG NOTIFY gChanged)
    Q_PROPERTY(int b READ b WRITE setB NOTIFY bChanged)

public:
    explicit EditableImage(QQuickItem *parent = 0);

    QImage image(){return mImage;}

    int r() const{return mR;}
    int g() const{return mG;}
    int b() const{return mB;}

signals:
    void imageChanged(QImage img);
    void rChanged(int r);
    void gChanged(int g);
    void bChanged(int b);

public slots:
    void setImage(const QImage&img);
    void setR(int r);
    void setG(int g);
    void setB(int b);
    void load(const QString&);

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

protected slots:
    void needUpdate(){update();}

protected:
    int mR;
    int mG;
    int mB;
    QImage mImage;
};

#endif // EDITABLEIMAGE_H
