#include <CommonAPI/CommonAPI.hpp>

#include <sstream>
#include <v0/commonapi/examples/E01HelloWorldStubDefault.hpp>

class E01HelloWorldStubImpl : public v0::commonapi::examples::E01HelloWorldStubDefault {
public:
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply);
};
