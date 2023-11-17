#include <iostream>
#include <vector>
#include <cstdio>
#include "benchmarking.h"
#include "io.h"

using namespace std;
using namespace Benchmarking;

int main(int argc, char* argv[])
{
    int trials = 10;
    vector<string> args(argv, argv + argc);

    if (args.empty())
    {
        throw runtime_error("Program expects an input file");
    }
    vector<string> output;
    string inputfile = args[1];

    for (int i = 0; i < trials; ++i)
    {
        output.clear();
        auto time = GetTimeMs64();
        IO::reserve_first::ifstream_method::pipe_newlines_read_line_by_line_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::istreambuf_reserve_and_readfile_directly_line_by_line(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::istream_reserve_and_readfile_directly_line_by_line(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::istreambuf_read_into_reserved_ss_and_get_wholefile_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::istreambuf_read_into_reserved_ss_and_get_wholefile(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::istreambuf_read_into_ss_and_get_wholefile_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::ifstream_read_wholefile_into_charlist_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::ifstream_method::ifstream_read_wholefile_into_charlist(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::C_method::read_FILE_wholefile_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_first::C_method::read_FILE_wholefile(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_not::ifstream_method::istreambuf_read_into_ss_and_get_wholefile(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_not::ifstream_method::istreambuf_copy_to_string_then_read_into_ss_and_get_wholefile(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_not::ifstream_method::ifstream_and_read_line_by_line(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_not::C_method::read_FILE_line_by_line_and_reserve(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

        output.clear();
        time = GetTimeMs64();
        IO::reserve_not::C_method::read_FILE_line_by_line(inputfile, output);
        cout << "Runtime: " << GetTimeMs64() - time << " ms" << endl;

    }

    return 0;
}
