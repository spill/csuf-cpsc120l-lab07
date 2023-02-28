// Ryan Trinh
// CPSC 120-06
// 2022-10-19
// rtrinh02@csu.fullerton.edu
// @rtrinh02
//
// Lab 08-01
// Partners: @rubenarmenta
//
// Search for palindrone
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& word) {
  std::string reverse_word{word.rbegin(), word.rend()};
  return word == reverse_word;
}

int main(int argc, char const* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file. Exiting.\n";
    return 1;
  }
  std::string input_file_name{args.at(1)};

  std::ifstream input_file_stream{input_file_name};
  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << input_file_name
              << ". Exiting.\n";
    return 1;
  }

  while (input_file_stream) {
    std::string line_buffer;
    std::getline(input_file_stream, line_buffer);
    if (line_buffer.size() > 3 && IsPalindrome(line_buffer)) {
      std::cout << line_buffer << "\n";
    }
  }

  input_file_stream.close();

  return 0;
}
