#include "E01HelloWorldStubImpl.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    //////////////////////////////////////////////////////////////////////////
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    //std::string instance = "commonapi.examples.Attributes";
    std::string connection = "service-sample";

    std::shared_ptr<E01HelloWorldStubImpl> myService = std::make_shared<E01HelloWorldStubImpl>();
    runtime->registerService(domain, instance, myService, connection);

    //////////////////////////////////////////////////////////////////////////

    return app.exec();
}
