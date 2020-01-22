#ifndef HELLOSTUBMAIN_H
#define HELLOSTUBMAIN_H

//#include <v1/proj/testcode/Test_CodeStub.hpp>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/proj/testcode/Test_CodeStubDefault.hpp>

class HelloStubMain {
public:
    HelloStubMain();
    void Init();
};

class StubImpl : public v1::proj::testcode::Test_CodeStubDefault {
};

#endif // HELLOSTUBMAIN_H
