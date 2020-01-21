#include "MyProxy.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <unistd.h>
#include <v0/commonapi/examples/E01HelloWorldProxy.hpp>

using namespace v0::commonapi::examples;

void recv_cb(const CommonAPI::CallStatus& callStatus, const int32_t& val)
{
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        std::cout << "Receive callback: " << val << std::endl;
    }
}

void test_val(const int32_t& val)
{
    std::cout << "Received change message[test]: " << val << std::endl;
}

void return_myStatus(const int32_t& val, const ::v0::commonapi::examples::E01HelloWorld::stdErrorTypeEnum& _Value2)
{
    std::cout << "return myStatus : " << val << std::endl;
    std::cout << "return myValue2 : " << _Value2 << std::endl;
}

void async_ex(const CommonAPI::CallStatus& callstatus, const std::string& return_msg)
{
    if (CommonAPI::CallStatus::SUCCESS == callstatus)
        std::cout << "output: " << return_msg << std::endl;
    else
        std::cout << "call status :  err\n";
}

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
    std::string connection = "client-sample";

    // smart pointer O
    std::shared_ptr<v0::commonapi::examples::E01HelloWorldProxyDefault> myProxy = runtime->buildProxy<v0::commonapi::examples::E01HelloWorldProxy>(domain, instance, connection);

    while (!myProxy->isAvailable())
        std::this_thread::sleep_for(std::chrono::microseconds(10));

    // getProxyStatusEvent() use
    //    if (nullptr != mMyProxy) {
    //        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));
    //    }

    const std::string name = "World";
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    // smart pointer X
    MyProxy* locMyProxy = new MyProxy;
    std::shared_ptr<MyProxy> locMyProxy2 = std::make_shared<MyProxy>();

    locMyProxy->sayHello("my world");
    locMyProxy2->sayHello("shared world");

    std::cout << "test0" << std::endl;

    myProxy->getXAttribute().getChangedEvent().subscribe(&test_val);
    myProxy->getMyStatusEvent().subscribe(&return_myStatus);

    CommonAPI::CallInfo info(10000);
    //info.sender_ = 5678;

    myProxy->sayHello(name, callStatus, returnMessage, &info);
    std::cout << "Got message: '" << returnMessage << "'\n";
    std::cout << "test1" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    ///////////////
    std::cout << "test3" << std::endl;

    myProxy->sayHelloAsync(name, &async_ex, &info);
    std::cout << "test4" << std::endl;

    //////////////
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call failed!\n";
        return -1;
    }
    //    std::cout << "Got message: '" << returnMessage << "'\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    delete locMyProxy;
    //////////////////////////////////////////////////////////////////////////

    std::this_thread::sleep_for(std::chrono::seconds(10));

    //////////////////////////////////////////////////////////////////////////

    //CommonAPI::CallStatus callStatus;
    int32_t value = -1;

    // Get actual attribute value from service
    std::cout << "Getting attribute value: " << value << std::endl;
    myProxy->getXAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!\n";
        return -1;
    }
    std::cout << "Got attribute value: " << value << std::endl;

    // Subscribe for receiving values
    //    myProxy->getXAttribute().getChangedEvent().subscribe([&](const int32_t& val) {
    //        std::cout << "Received change message: " << val << std::endl;
    //    });

    // Asynchronous call to set attribute of service
    std::function<void(const CommonAPI::CallStatus&, const int32_t)> fcb = recv_cb;
    value = 100;
    myProxy->getXAttribute().setValueAsync(value, fcb, &info);
    std::cout << "result1 : " << value << std::endl;

    int returnValue = 0;
    value = -100;
    myProxy->getXAttribute().setValue(value, callStatus, returnValue);
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        std::cout << "result2 : " << value << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////

    return app.exec();
}
