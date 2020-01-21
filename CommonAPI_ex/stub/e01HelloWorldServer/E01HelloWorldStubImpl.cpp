#include "E01HelloWorldStubImpl.h"
#include <iostream>

using myStdErrType = v0::commonapi::examples::E01HelloWorld::stdErrorTypeEnum;

void E01HelloWorldStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply)
{
    (void)_client;
    //get x attribute
    int32_t stub_val = getXAttribute();

    //for 10 times x + 1 set
    for (int i = 0; i < 10; i++) {
        setXAttribute(++stub_val);
    }

    std::stringstream messageStream;

    messageStream << "Hello " << _name << "!";
    std::cout << "sayHello('" << _name << "'): '" << messageStream.str() << "'\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    fireMyStatusEvent(stub_val, myStdErrType::MY_FAULT);

    _reply(messageStream.str());
};
