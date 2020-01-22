#include "HelloProxyMain.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

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

    /////////////////////////////////////////////
    //HelloProxyMain* proxyInst = new HelloProxyMain();
    // 위 형식 사용시 해제 조건 필요

    std::shared_ptr<HelloProxyMain> proxyInst = std::make_shared<HelloProxyMain>();
    proxyInst->InitAsync();

    /////////////////////////////////////////////
    return app.exec();
}
