#include <vector>
#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qt/qml/FileoModule/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection
    );
    engine.load(url);

    std::cout << boost::filesystem::current_path() << std::endl;

    return app.exec();
}