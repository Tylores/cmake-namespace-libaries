#include <iostream>
#include "include/echo/echo.hpp"
#include "include/echo/formal_echo.hpp"


int main(int argc, char const *argv[])
{
    base::echo("Hello World!");
    formal::echo("Hello there, what are you doing!", "John!");
    return 0;
}
