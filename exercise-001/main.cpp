#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

// .bss segment
int foo;

// data segment
int data = 4711;

// rodata segment
const int rodata = 42;

auto main(int argc, char **argv) -> int
{
    fmt::print("Value of variable foo: {}, Address of variable foo: {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of variable data: {}, Address of variable data: {}\n", data, fmt::ptr(&data));
    fmt::print("Value of variable rodata: {}, Address of variable rodata: {}\n", rodata, fmt::ptr(&rodata));
    return 0; 
}
