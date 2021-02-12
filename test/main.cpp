#include <iostream>
#include "echo/formal_echo.hpp"
#include "echo/base"


int main(int argc, char const *argv[])
{
    base::echo("Hello World!");
    formal::echo("Hello there, what are you doing!", "John!");
    return 0;
}
