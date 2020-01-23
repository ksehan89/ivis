#ifndef HELLOPROXYMAIN_H
#define HELLOPROXYMAIN_H

#include <v1/proj/testcode/CommonTypes.hpp>
#include <v1/proj/testcode/Test_CodeProxy.hpp>

class HelloProxyMain {
public:
    HelloProxyMain() {}
    void InitAsync();

private:
    void callbackConnectionStatusChanged(const CommonAPI::AvailabilityStatus& availabilityStatus);
    void attribute_changed(const v1::proj::testcode::CommonTypes::a2Struct& strAVal);

private:
    std::shared_ptr<v1::proj::testcode::Test_CodeProxyDefault> mMyProxy;
};

#endif // HELLOPROXYMAIN_H
