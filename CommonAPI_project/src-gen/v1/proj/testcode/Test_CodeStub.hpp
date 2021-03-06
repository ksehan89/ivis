/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201907221047.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_TESTCODE_Test__Code_STUB_HPP_
#define V1_PROJ_TESTCODE_Test__Code_STUB_HPP_

#include <functional>
#include <sstream>



#include <v1/proj/testcode/CommonTypes.hpp>

#include <v1/proj/testcode/Test_Code.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <vector>

#include <mutex>

#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace testcode {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service Test_Code. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class Test_CodeStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual Test_Code {
 public:
    ///Notifies all remote listeners about a change of value of the attribute speedValue.
    virtual void fireSpeedValueAttributeChanged(const int32_t& speedValue) = 0;
    ///Notifies all remote listeners about a change of value of the attribute rpmValue.
    virtual void fireRpmValueAttributeChanged(const int32_t& rpmValue) = 0;
    ///Notifies all remote listeners about a change of value of the attribute a2.
    virtual void fireA2AttributeChanged(const ::v1::proj::testcode::CommonTypes::a2Struct& a2) = 0;



    virtual void deactivateManagedInstances() = 0;

    void lockSpeedValueAttribute(bool _lockAccess) {
        if (_lockAccess) {
            speedValueMutex_.lock();
        } else {
            speedValueMutex_.unlock();
        }
    }
    void lockRpmValueAttribute(bool _lockAccess) {
        if (_lockAccess) {
            rpmValueMutex_.lock();
        } else {
            rpmValueMutex_.unlock();
        }
    }
    void lockA2Attribute(bool _lockAccess) {
        if (_lockAccess) {
            a2Mutex_.lock();
        } else {
            a2Mutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */

    std::recursive_mutex speedValueMutex_;
    std::recursive_mutex rpmValueMutex_;
    std::recursive_mutex a2Mutex_;
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for Test_Code.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class Test_CodeStubRemoteEvent
{
public:
    virtual ~Test_CodeStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute speedValue
    virtual bool onRemoteSetSpeedValueAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) = 0;
    /// Action callback for remote set requests on the attribute speedValue
    virtual void onRemoteSpeedValueAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute rpmValue
    virtual bool onRemoteSetRpmValueAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) = 0;
    /// Action callback for remote set requests on the attribute rpmValue
    virtual void onRemoteRpmValueAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute a2
    virtual bool onRemoteSetA2Attribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::v1::proj::testcode::CommonTypes::a2Struct _value) = 0;
    /// Action callback for remote set requests on the attribute a2
    virtual void onRemoteA2AttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service Test_Code to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class Test_CodeStub
    : public virtual CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>
{
public:
    typedef std::function<void (int32_t _output_num)>num_exReply_t;

    virtual ~Test_CodeStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }

    /// Provides getter access to the attribute speedValue
    virtual const int32_t &getSpeedValueAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireSpeedValueAttributeChanged(int32_t _value) {
    auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireSpeedValueAttributeChanged(_value);
    }
    void lockSpeedValueAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockSpeedValueAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute rpmValue
    virtual const int32_t &getRpmValueAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireRpmValueAttributeChanged(int32_t _value) {
    auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireRpmValueAttributeChanged(_value);
    }
    void lockRpmValueAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockRpmValueAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute a2
    virtual const ::v1::proj::testcode::CommonTypes::a2Struct &getA2Attribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireA2AttributeChanged(::v1::proj::testcode::CommonTypes::a2Struct _value) {
    auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireA2AttributeChanged(_value);
    }
    void lockA2Attribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockA2Attribute(_lockAccess);
    }

    /// This is the method that will be called on remote calls on the method num_ex.
    virtual void num_ex(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _input_num, num_exReply_t _reply) = 0;

    
    using CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<Test_CodeStubAdapter, Test_CodeStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef Test_CodeStubRemoteEvent RemoteEventType;
    typedef Test_Code StubInterface;
};

} // namespace testcode
} // namespace proj
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_TESTCODE_Test__Code_STUB_HPP_
