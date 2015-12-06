#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "editableimage.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<EditableImage>("My.EditableImage", 1, 0, "EditableImage");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

