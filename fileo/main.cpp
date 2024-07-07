#include <vector>
#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "../algorithms/Sorting.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(u"qrc:/qt/qml/FileoModule/Main.qml"_qs);

    int arr[]  = {1,5,7,2};
    Sorting::selectionSort(arr, 4);

    return app.exec();

}