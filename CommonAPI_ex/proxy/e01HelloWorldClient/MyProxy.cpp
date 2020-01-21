#include "MyProxy.h"
#include <iostream>

std::string MyProxy::sayHello(std::string contents)
{
    std::cout << "Hello " << contents << std::endl;
    return contents;
}
