#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "stdio.h"
#include <algorithm>    // std::sort

auto main(int argc, char **argv) -> int
{
    int count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, fmt::format("Create a vector with the given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Created a vector with {} elements\n", count);
    /* INSERT YOUR CODE HERE */

    std::vector<int> vector(count);
    for (int i = 0; i<count; i++)
    {
        vector[i] = rand() % 100 + 1;
    }
    
    for (int num : vector) {
        fmt::print("{} ", num);
    }

    auto start = std::chrono::system_clock::now();

    /* TIMED FUCTION */
    std::sort(vector.begin(), vector.end());
    /* END TIMED FUNCTION*/
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("\nSorted Vector:\n");
    for (int num : vector) {
        fmt::print("{} ", num);
    }
    fmt::print("\nTime for sorting: {}\n", elapsed);

    return 0; /* exit gracefully*/
}
