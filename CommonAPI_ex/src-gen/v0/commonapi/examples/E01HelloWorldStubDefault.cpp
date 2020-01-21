/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201907221047.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v0/commonapi/examples/E01HelloWorldStubDefault.hpp>
#include <assert.h>

namespace v0 {
namespace commonapi {
namespace examples {

E01HelloWorldStubDefault::E01HelloWorldStubDefault():
        remoteEventHandler_(this),
        interfaceVersion_(E01HelloWorld::getInterfaceVersion()) {
}

const CommonAPI::Version& E01HelloWorldStubDefault::getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
    (void)_client;
    return interfaceVersion_;
}

E01HelloWorldStubRemoteEvent* E01HelloWorldStubDefault::initStubAdapter(const std::shared_ptr< E01HelloWorldStubAdapter> &_adapter) {
    CommonAPI::Stub<E01HelloWorldStubAdapter, E01HelloWorldStubRemoteEvent>::stubAdapter_ = _adapter;
    return &remoteEventHandler_;
}

 const int32_t& E01HelloWorldStubDefault::getXAttribute() {
     return xAttributeValue_;
 }

 const int32_t& E01HelloWorldStubDefault::getXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
     (void)_client;
     return getXAttribute();
 }

 void E01HelloWorldStubDefault::setXAttribute(int32_t _value) {
     std::shared_ptr<E01HelloWorldStubAdapter> stubAdapter = CommonAPI::Stub<E01HelloWorldStubAdapter,
     E01HelloWorldStubRemoteEvent>::stubAdapter_.lock();
     if(stubAdapter) {
         stubAdapter->lockXAttribute(true);
         const bool valueChanged = (xAttributeValue_ != _value);
         if (valueChanged) {
             xAttributeValue_ = std::move(_value);
             fireXAttributeChanged(xAttributeValue_);
         }
         stubAdapter->lockXAttribute(false);
     } else {
         const bool valueChanged = trySetXAttribute(std::move(_value));
         if (valueChanged) {
             fireXAttributeChanged(xAttributeValue_);
         }
     }
}

 bool E01HelloWorldStubDefault::trySetXAttribute(int32_t _value) {
     if (!validateXAttributeRequestedValue(_value))
         return false;

     bool valueChanged;
     std::shared_ptr<E01HelloWorldStubAdapter> stubAdapter = CommonAPI::Stub<E01HelloWorldStubAdapter, E01HelloWorldStubRemoteEvent>::stubAdapter_.lock();
     if(stubAdapter) {
         stubAdapter->lockXAttribute(true);
         valueChanged = (xAttributeValue_ != _value);
         xAttributeValue_ = std::move(_value);
         stubAdapter->lockXAttribute(false);
     } else {
         valueChanged = (xAttributeValue_ != _value);
         xAttributeValue_ = std::move(_value);
     }

     return valueChanged;
 }

 bool E01HelloWorldStubDefault::validateXAttributeRequestedValue(const int32_t &_value) {
     (void)_value;
     return true;
 }

 void E01HelloWorldStubDefault::setXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) {
     (void)_client;
     setXAttribute(_value);
 }

 void E01HelloWorldStubDefault::onRemoteXAttributeChanged() {
     // No operation in default
 }

 void E01HelloWorldStubDefault::RemoteEventHandler::onRemoteXAttributeChanged() {
     assert(defaultStub_ !=NULL);
     defaultStub_->onRemoteXAttributeChanged();
 }

 bool E01HelloWorldStubDefault::RemoteEventHandler::onRemoteSetXAttribute(int32_t _value) {
     assert(defaultStub_ !=NULL);
     return defaultStub_->trySetXAttribute(std::move(_value));
 }

 bool E01HelloWorldStubDefault::RemoteEventHandler::onRemoteSetXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) {
     (void)_client;
     return onRemoteSetXAttribute(_value);
 }


void E01HelloWorldStubDefault::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) {
    (void)_client;
    (void)_name;
    std::string message = "";
    _reply(message);
}


void E01HelloWorldStubDefault::fireMyStatusEvent(const int32_t &_myCurrentValue, const ::v0::commonapi::examples::E01HelloWorld::stdErrorTypeEnum &_Value2) {
    if (!_Value2.validate()) {
        return;
    }
    E01HelloWorldStub::fireMyStatusEvent(_myCurrentValue, _Value2);
}


E01HelloWorldStubDefault::RemoteEventHandler::RemoteEventHandler(E01HelloWorldStubDefault *_defaultStub)
    : 
      defaultStub_(_defaultStub) {
}

} // namespace examples
} // namespace commonapi
} // namespace v0
