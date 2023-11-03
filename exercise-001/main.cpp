#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

// bss segment
int bss;
int bss2;
// data segment
int data = 4711;
int data2 = 4711;
// rodata segment
const int rodata = 42;
const int rodata2 = 42;

auto main(int argc, char **argv) -> int
{
    int stack = 0;
    fmt::print("Value of variable bss: {}, Address of variable bss: {}\n", bss, fmt::ptr(&bss));
    fmt::print("Value of variable bss2: {}, Address of variable bss2: {}\n", bss2, fmt::ptr(&bss2));
    fmt::print("Value of variable data: {}, Address of variable data: {}\n", data, fmt::ptr(&data));
    fmt::print("Value of variable data2: {}, Address of variable data2: {}\n", data2, fmt::ptr(&data2));
    fmt::print("Value of variable rodata: {}, Address of variable rodata: {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of variable rodata2: {}, Address of variable rodata2: {}\n", rodata2, fmt::ptr(&rodata2));
    fmt::print("Value of variable stack: {}, Address of variable stack: {}\n", stack, fmt::ptr(&stack));
    return 0; 
}
