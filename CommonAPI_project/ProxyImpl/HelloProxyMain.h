#ifndef HELLOPROXYMAIN_H
#define HELLOPROXYMAIN_H

#include <v1/proj/testcode/Test_CodeProxy.hpp>

class HelloProxyMain {
public:
    HelloProxyMain() {}
    void InitAsync();

private:
    void callbackConnectionStatusChanged(const CommonAPI::AvailabilityStatus& availabilityStatus);

private:
    std::shared_ptr<v1::proj::testcode::Test_CodeProxyDefault> mMyProxy;
};

#endif // HELLOPROXYMAIN_H
