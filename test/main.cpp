#include <iostream>
#include "echo/base/echo.hpp"
#include "formal_echo.hpp"

int main(int argc, char const *argv[])
{
    base::echo("Hello World!");
    formal::echo("Hello there!", "John!");
    return 0;
}
