#ifndef HELLOSTUBMAIN_H
#define HELLOSTUBMAIN_H

//#include <v1/proj/testcode/Test_CodeStub.hpp>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/proj/testcode/Test_CodeStubDefault.hpp>

class StubImpl;

class HelloStubMain {
public:
    static HelloStubMain* getInstance();
    StubImpl* getMyServiceInst();
    void Init();

private:
    HelloStubMain();
    std::shared_ptr<StubImpl> mMyService;
};

class StubImpl : public v1::proj::testcode::Test_CodeStubDefault {
public:
    //    static int injection_callback(uint32_t service_id, void* data, uint32_t length);
};

#endif // HELLOSTUBMAIN_H
