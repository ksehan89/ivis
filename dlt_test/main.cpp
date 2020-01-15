#include "dlt_common.h"
#include "dltregistration.h"
#include "dltregistration_global.h"
#include "dltregistration_p.h"
#include <QDebug>
#include <QGuiApplication>
#include <QHash>
#include <QLoggingCategory>
#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>
#include <QtCore/qglobal.h>
#include <dlt/dlt.h>

//DLT_DECLARE_CONTEXT(myContext1);
//DLT_DECLARE_CONTEXT(myContext2);
//DLT_DECLARE_CONTEXT(myContext3);
//DLT_DECLARE_CONTEXT(ContextDefault)
Q_LOGGING_CATEGORY(DevDigitalCluster, "DCLU.DigitalClusterHMI.Common");

int dlt_example();
int injection_callback(uint32_t service_id, void* data, uint32_t length);

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    DltRegistration* dlt = globalDltRegistration();

    dlt->registerApplication("hmia1", "HMDC.ClusterHMI1");

    dlt->registerCategory(&DevDigitalCluster(), "dccm1", "HMDC.ClusterHMI.Common1");

    globalDltRegistration()->setMinLogLevel(QtDebugMsg);

    qInstallMessageHandler(&(DltRegistration::messageHandler));

    qCDebug(DevDigitalCluster) << " test log ~~~~~";

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    DLT_REGISTER_INJECTION_CALLBACK(*dlt->getDltContext(&DevDigitalCluster()), 0x1000, injection_callback);
    //    dlt_example();

    return app.exec();
}

int dlt_example()
{
    //DLT_REGISTER_INJECTION_CALLBACK(CONTEXT, SERVICEID, CALLBACK);
    //dlt_register_injection_callback(DltContext, )

    /* register application */
    //DLT_REGISTER_APP("MAPP", "Test Application for Logging");
    //    dlt->registerApplication("hmia1", "HMDC.ClusterHMI1");

    /* register all contexts */
    //DLT_REGISTER_CONTEXT(myContext1, "TES1", "Test context 1 for Logging");
    //DLT_REGISTER_CONTEXT(myContext2, "TES2", "Test context 2 for Logging");
    //DLT_REGISTER_CONTEXT(myContext3, "TES3", "Test context 3 for Logging");
    //    dlt->registerCategory(&DevDigitalCluster(), "dccm1", "HMDC.ClusterHMI.Common1");

    /* Write your logs */
    //DLT_LOG(myContext3, DLT_LOG_DEFAULT, DLT_INT(5), DLT_STRING("DLT_LOG_DEFAULT"));
    //DLT_LOG(myContext3, DLT_LOG_OFF, DLT_INT(5), DLT_STRING("DLT_LOG_OFF"));
    //DLT_LOG(myContext3, DLT_LOG_FATAL, DLT_INT(5), DLT_STRING("DLT_LOG_FATAL"));
    //DLT_LOG(myContext1, DLT_LOG_ERROR, DLT_INT(5), DLT_STRING("DLT_LOG_ERROR"));
    //DLT_LOG(myContext3, DLT_LOG_WARN, DLT_INT(5), DLT_STRING("DLT_LOG_WARN"));
    //DLT_LOG(myContext2, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("DLT_LOG_INFO"));
    //DLT_LOG(myContext3, DLT_LOG_DEBUG, DLT_INT(5), DLT_STRING("DLT_LOG_DEBUG"));
    //DLT_LOG(myContext3, DLT_LOG_VERBOSE, DLT_INT(5), DLT_STRING("DLT_LOG_VERBOSE"));
    //DLT_LOG(myContext3, DLT_LOG_MAX, DLT_INT(5), DLT_STRING("DLT_LOG_MAX"));
    //    globalDltRegistration()->setMinLogLevel(QtDebugMsg);

    /* Sleep some time to avoid a flaw in dlt-daemon that would eat your messages
        if you deregister while it still processes your registration */
    //    sleep(3);

    /* unregister your contexts */
    //    DLT_UNREGISTER_CONTEXT(myContext1);
    //    DLT_UNREGISTER_CONTEXT(myContext2);
    //    DLT_UNREGISTER_CONTEXT(myContext3);

    /* unregister your application */
    //    DLT_UNREGISTER_APP();

    return 0;
}

int injection_callback(uint32_t service_id, void* data, uint32_t length)
{
    //char text[1024];
    //    DLT_LOG(ContextDefault, DLT_LOG_DEFAULT, DLT_INT(5), DLT_STRING("DLT_LOG_DEFAULT"));
    qCDebug(DevDigitalCluster) << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2 ";
    //DLT_LOG(ContextDefault, DLT_LOG_INFO, DLT_STRING("Injection: "), DLT_UINT32(service_id));
    //    printf("Injection %d, Length=%d \n", service_id, length);

    //    if (length > 0) {
    //        dlt_print_mixed_string(text, 1024, data, length, 0);
    //        DLT_LOG(ContextDefault, DLT_LOG_INFO, DLT_STRING("Data: "), DLT_STRING(text));
    //        printf("%s \n", text);
    //    }

    return 0;
}
