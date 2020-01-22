#include "HelloProxyMain.h"
#include <CommonAPI/CommonAPI.hpp>
#include <v1/proj/testcode/Test_CodeProxy.hpp>

void speedValue(const int32_t& speedVal)
{
    std::cout << "Receive speedValue : " << speedVal << std::endl;
}

void rpmValue(const int32_t& rpmVal)
{
    std::cout << "Receive rpmValue : " << rpmVal << std::endl;
}

void HelloProxyMain::callbackConnectionStatusChanged(const CommonAPI::AvailabilityStatus& availabilityStatus)
{
    //    int a = 10;
    //    double b = 0.;
    //    b = (double)a;
    //    b = static_cast<double>(a);
    std::cout << "Return status : " << static_cast<std::underlying_type<CommonAPI::AvailabilityStatus>::type>(availabilityStatus) << std::endl;
    if (availabilityStatus != CommonAPI::AvailabilityStatus::AVAILABLE) {
    } else {
        //attribute chage event subscribe
        mMyProxy->getSpeedValueAttribute().getChangedEvent().subscribe(&speedValue);
        mMyProxy->getRpmValueAttribute().getChangedEvent().subscribe(&rpmValue);
    }
}

void HelloProxyMain::InitAsync()
{
    std::string domain = "local";
    std::string instance = "proj.testcode.Test_Code";
    std::string connection = "client-sample";

    mMyProxy = CommonAPI::Runtime::get()->buildProxy<v1::proj::testcode::Test_CodeProxy>(domain, instance, connection);

    if (nullptr != mMyProxy) {
        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));
    }

    //    if (nullptr != mMyProxy) {
    //        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));
    //    } else {
    //        std::cerr << "Can't build proxy!" << std::endl;
    //        return;
    //    }

    //mMyProxy->getSpeedValueAttribute().getChangedEvent().subscribe(&speedValue);
}