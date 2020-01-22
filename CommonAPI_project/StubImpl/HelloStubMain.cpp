#include "HelloStubMain.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QDebug>
#include <QLoggingCategory>
#include <dlt/dlt.h>
#include <dlt_common.h>
//#include <dltregistration.h>
//#include <dltregistration_global.h>
//#include <dltregistration_p.h>
#include <v1/proj/testcode/Test_CodeStub.hpp>

HelloStubMain::HelloStubMain()
{
}

//Q_LOGGING_CATEGORY(DevDigitalCluster, "DCLU.DigitalClusterHMI.Common");

////injection func -> rpm, speed value change
//int injection_callback(uint32_t service_id, void* data, uint32_t length)
//{
//    qCDebug(DevDigitalCluster) << "Dlt injection : ";
//    return 0;
//}

void HelloStubMain::Init()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "proj.testcode.Test_Code";
    std::string connection = "service-sample";

    //register service
    std::shared_ptr<StubImpl> myService = std::make_shared<StubImpl>();
    runtime->registerService(domain, instance, myService, connection);

    //dlt
    // Register application
    DLT_DECLARE_CONTEXT(myContext1);
    DLT_DECLARE_CONTEXT(speedValue);
    DLT_DECLARE_CONTEXT(rpmValue);

    // register all contexts
    DLT_REGISTER_APP("MAPP", "Test Application for Logging");

    // write your logs
    DLT_REGISTER_CONTEXT(myContext1, "tes1", "Test Context 1 for Logging");
    DLT_REGISTER_CONTEXT(speedValue, "tes2", "speedValue : ");
    DLT_REGISTER_CONTEXT(rpmValue, "tes3", "rpmValue : ");

    DLT_LOG(myContext1, DLT_LOG_ERROR, DLT_INT(6), DLT_STRING("This is a error"));
    DLT_LOG(speedValue, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("This is a info"));
    DLT_LOG(rpmValue, DLT_LOG_DEBUG, DLT_INT(5), DLT_STRING("This is a debug"));

    // dlt injection
    //DLT_INJECTION_CALLBACK(CONTEXT, SERVICEID, CALLBACK);
    //DLT_INJECTION_CALLBACK(myContext1, , injection_callback());

    // unregister your contexts
    DLT_UNREGISTER_CONTEXT(myContext1);
    DLT_UNREGISTER_CONTEXT(speedValue);
    DLT_UNREGISTER_CONTEXT(rpmValue);

    // unregister your application
    DLT_UNREGISTER_APP();

    //    //dlt injection func register
    //    DltRegistration* dlt = globalDltRegistration();
    //    dlt->registerApplication("hmia1", "HMDC.ClusterHMI1");
    //    dlt->registerCategory(&DevDigitalCluster(), "dccm1", "HMDC.ClusterHMI.Common1");
    //    globalDltRegistration()->setMinLogLevel(QtDebugMsg);
    //    qInstallMessageHandler(&(DltRegistration::messageHandler));

    //    DLT_REGISTER_INJECTION_CALLBACK(*dlt->getDltContext(&DevDigitalCluster()), 0x1000, injection_callback);
}
