/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201907221047.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_TESTCODE_Test__Code_PROXY_HPP_
#define V1_PROJ_TESTCODE_Test__Code_PROXY_HPP_

#include <v1/proj/testcode/Test_CodeProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/AttributeExtension.hpp>
#include <CommonAPI/Factory.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace testcode {

template <typename ... _AttributeExtensions>
class Test_CodeProxy
    : virtual public Test_Code,
      virtual public Test_CodeProxyBase,
      virtual public _AttributeExtensions... {
public:
    Test_CodeProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~Test_CodeProxy();

    typedef Test_Code InterfaceType;


    /**
     * Returns the wrapper class that provides access to the attribute speedValue.
     */
    virtual SpeedValueAttribute& getSpeedValueAttribute() {
        return delegate_->getSpeedValueAttribute();
    }
    /**
     * Returns the wrapper class that provides access to the attribute rpmValue.
     */
    virtual RpmValueAttribute& getRpmValueAttribute() {
        return delegate_->getRpmValueAttribute();
    }




    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

 private:
    std::shared_ptr< Test_CodeProxyBase> delegate_;
};

typedef Test_CodeProxy<> Test_CodeProxyDefault;

namespace Test_CodeExtensions {
    template <template <typename > class _ExtensionType>
    class SpeedValueAttributeExtension {
     public:
        typedef _ExtensionType< Test_CodeProxyBase::SpeedValueAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension< Test_CodeProxyBase::SpeedValueAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        SpeedValueAttributeExtension(Test_CodeProxyBase& proxy): attributeExtension_(proxy.getSpeedValueAttribute()) {
        }
    
        inline extension_type& getSpeedValueAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

    template <template <typename > class _ExtensionType>
    class RpmValueAttributeExtension {
     public:
        typedef _ExtensionType< Test_CodeProxyBase::RpmValueAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension< Test_CodeProxyBase::RpmValueAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        RpmValueAttributeExtension(Test_CodeProxyBase& proxy): attributeExtension_(proxy.getRpmValueAttribute()) {
        }
    
        inline extension_type& getRpmValueAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

} // namespace Test_CodeExtensions

//
// Test_CodeProxy Implementation
//
template <typename ... _AttributeExtensions>
Test_CodeProxy<_AttributeExtensions...>::Test_CodeProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< Test_CodeProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< Test_CodeProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
Test_CodeProxy<_AttributeExtensions...>::~Test_CodeProxy() {
}


template <typename ... _AttributeExtensions>
const CommonAPI::Address &Test_CodeProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool Test_CodeProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool Test_CodeProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& Test_CodeProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& Test_CodeProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


} // namespace testcode
} // namespace proj
} // namespace v1

namespace CommonAPI {
template<template<typename > class _AttributeExtension>
struct DefaultAttributeProxyHelper< ::v1::proj::testcode::Test_CodeProxy,
    _AttributeExtension> {
    typedef typename ::v1::proj::testcode::Test_CodeProxy<
            ::v1::proj::testcode::Test_CodeExtensions::SpeedValueAttributeExtension<_AttributeExtension>, 
            ::v1::proj::testcode::Test_CodeExtensions::RpmValueAttributeExtension<_AttributeExtension>
    > class_t;
};
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_TESTCODE_Test__Code_PROXY_HPP_
