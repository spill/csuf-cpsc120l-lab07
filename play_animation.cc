// Ryan Trinh
// CPSC 120-06
// 2022-10-19
// rtrinh02@csu.fullerton.edu
// @rtrinh02
//
// Lab 08-03
// Partners: @rubenarmenta
//
// Play Animation
//

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main(int argc, char const* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file.\n";
    return 1;
  }
  std::string input_file_name{args.at(1)};

  std::ifstream input_file_stream{input_file_name};
  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << input_file_name
              << ". Exiting.\n";
    return 1;
  }

  char letter{0};
  while (input_file_stream.get(letter)) {
    std::cout << letter;
    std::this_thread::sleep_for(2000us);
  }
  input_file_stream.close();

  return 0;
}
