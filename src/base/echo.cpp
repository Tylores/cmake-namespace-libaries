#include <iostream>
#include "include/echo/echo.hpp"
namespace base
{
    void echo(const std::string& message) 
    {
        std::cout << message << std::endl;
    }
}