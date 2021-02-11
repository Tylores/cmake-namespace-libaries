#include <iostream>
#include "formal_echo.hpp"

namespace formal
{
    void echo(const std::string& message, const std::string& name) 
    {
        std::cout << name << " : " << message << std::endl;
    }
}