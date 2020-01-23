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

void num_ex(const int32_t& input_num)
{
    std::cout << "Receive input_num : " << input_num << std::endl;
}

void recv_cb(const CommonAPI::CallStatus& callStatus, const int32_t val)
{
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        std::cout << "receive callback: " << val << std::endl;
    }
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

        // A2 attribute 호출
        mMyProxy->getA2Attribute().getChangedEvent().subscribe(std::bind(&HelloProxyMain::attribute_changed, this, std::placeholders::_1));

        ///////////////////////////////////

        const int input_num = 0;
        int output_num = 0;
        CommonAPI::CallStatus callStatus;
        CommonAPI::CallInfo info(1000);

        std::cout << "output_num_test : " << output_num << std::endl;

        // num_ex function 호출
        mMyProxy->num_ex(input_num, callStatus, output_num, &info);
        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            //return -1;
        }
        std::cout << "input_num_proxy : " << input_num << std::endl;
        std::cout << "output_num_test3 : " << output_num << std::endl;

        v1::proj::testcode::CommonTypes::a2Struct requestValue;
        v1::proj::testcode::CommonTypes::a2Struct responseValue;

        // set
        requestValue.setA(100);
        requestValue.setB(true);
        requestValue.setD(3.14);

        mMyProxy->getA2Attribute().setValue(requestValue, callStatus, responseValue);

        ///////////////////////////////////
    }
}

// attribute value changed, output
void HelloProxyMain::attribute_changed(const v1::proj::testcode::CommonTypes::a2Struct& strAVal)
{
    std::cout << "attribute_changed_int : " << strAVal.getA() << std::endl;
    std::cout << "attribute_changed_bool : " << strAVal.getB() << std::endl;
    std::cout << "attribute_changed_double : " << strAVal.getD() << std::endl;
}

void HelloProxyMain::InitAsync()
{
    std::string domain = "local";
    std::string instance = "proj.testcode.Test_Code";
    std::string connection = "client-sample";

    mMyProxy = CommonAPI::Runtime::get()->buildProxy<v1::proj::testcode::Test_CodeProxy>(domain, instance, connection);

    if (nullptr != mMyProxy) {
        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));

        std::function<void(const CommonAPI::CallStatus&, const int32_t)> fcb = recv_cb;
    }

    //    if (nullptr != mMyProxy) {
    //        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));
    //    } else {
    //        std::cerr << "Can't build proxy!" << std::endl;
    //        return;
    //    }

    //mMyProxy->getSpeedValueAttribute().getChangedEvent().subscribe(&speedValue);
}
