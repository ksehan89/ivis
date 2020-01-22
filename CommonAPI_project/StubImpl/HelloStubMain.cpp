#include "HelloStubMain.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QDebug>
#include <QLoggingCategory>
#include <dlt/dlt.h>
#include <iostream>
//#include <dlt_common.h>
//#include <dltregistration.h>
//#include <dltregistration_global.h>
//#include <dltregistration_p.h>
#include <v1/proj/testcode/Test_CodeStub.hpp>

HelloStubMain::HelloStubMain()
    : mMyService(nullptr)
{
}

//Q_LOGGING_CATEGORY(DevDigitalCluster, "DCLU.DigitalClusterHMI.Common");

// Register application
DLT_DECLARE_CONTEXT(myContext1);
DLT_DECLARE_CONTEXT(myContext2);
DLT_DECLARE_CONTEXT(rpmValue);

////injection func -> rpm, speed value change
int injection_callback(uint32_t service_id, void* data, uint32_t length)
{
    //qCDebug(DevDigitalCluster) << "Dlt injection : ";

    int32_t speedValue = -1;
    if (HelloStubMain::getInstance()->getMyServiceInst() != nullptr) {
        speedValue = HelloStubMain::getInstance()->getMyServiceInst()->getSpeedValueAttribute();
        DLT_LOG(myContext2, DLT_LOG_INFO, DLT_STRING("get speedValeu : "), DLT_INT(speedValue));
        HelloStubMain::getInstance()->getMyServiceInst()->setSpeedValueAttribute(++speedValue);
        DLT_LOG(myContext2, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("set speedValeu : "), DLT_INT(speedValue));
    }
    DLT_LOG(myContext2, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("speedValeu : "), DLT_INT(speedValue));
    return 0;
}

HelloStubMain* HelloStubMain::getInstance()
{
    static HelloStubMain* sHellowStaticMain = nullptr;
    if (sHellowStaticMain == nullptr) {
        std::cout << "HelloStubMain created!\n ";
        sHellowStaticMain = new HelloStubMain();
    }

    return sHellowStaticMain;
}

StubImpl* HelloStubMain::getMyServiceInst()
{
    return mMyService.get();
}

void HelloStubMain::Init()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "proj.testcode.Test_Code";
    std::string connection = "service-sample";

    //register service
    mMyService = std::make_shared<StubImpl>();
    runtime->registerService(domain, instance, mMyService, connection);

    //dlt

    // register all contexts
    DLT_REGISTER_APP("MAPP", "Test Application for Logging");

    // write your logs
    DLT_REGISTER_CONTEXT(myContext1, "tes1", "Test Context 1 for Logging");
    DLT_REGISTER_CONTEXT(myContext2, "tes2", "speedValue : ");
    DLT_REGISTER_CONTEXT(rpmValue, "tes3", "rpmValue : ");

    DLT_LOG(myContext1, DLT_LOG_ERROR, DLT_INT(5), DLT_STRING("This is a error"));
    DLT_LOG(myContext2, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("This is a info"));
    DLT_LOG(rpmValue, DLT_LOG_INFO, DLT_INT(5), DLT_STRING("This is a debug"));

    // dlt injection
    //DLT_INJECTION_CALLBACK(CONTEXT, SERVICEID, CALLBACK);
    DLT_REGISTER_INJECTION_CALLBACK(myContext1, 0x1000, &injection_callback);

    // unregister your contexts
    //    DLT_UNREGISTER_CONTEXT(myContext1);
    //    DLT_UNREGISTER_CONTEXT(speedValue);
    //    DLT_UNREGISTER_CONTEXT(rpmValue);

    // unregister your application
    //DLT_UNREGISTER_APP();

    //    //dlt injection func register
    //    DltRegistration* dlt = globalDltRegistration();
    //    dlt->registerApplication("hmia1", "HMDC.ClusterHMI1");
    //    dlt->registerCategory(&DevDigitalCluster(), "dccm1", "HMDC.ClusterHMI.Common1");
    //    globalDltRegistration()->setMinLogLevel(QtDebugMsg);
    //    qInstallMessageHandler(&(DltRegistration::messageHandler));
}
