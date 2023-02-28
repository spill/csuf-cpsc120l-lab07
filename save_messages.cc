// Ryan Trinh
// CPSC 120-06
// 2022-10-19
// rtrinh02@csu.fullerton.edu
// @rtrinh02
//
// Lab 08-01
// Partners: @rubenarmenta
//
// Write a message to a file.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file.\n";
    return 1;
  }
  std::string output_file_name{args.at(1)};

  std::ofstream output_file_stream(output_file_name);
  if (!output_file_stream.is_open()) {
    std::cout << "Could not open the file " << output_file_name
              << ". Exiting.\n";
    return 1;
  }

  std::string secret_message;

  std::cout
      << "What's a secret message that you'd like to write into a file?\n";
  std::cout << "Type your message out and when you're done ";
  std::cout << "press return or enter.\n";

  std::getline(std::cin, secret_message, '\n');

  output_file_stream << secret_message << "\n";

  std::cout << "Your secret message was saved into " << output_file_name
            << ".\n";

  output_file_stream.close();

  return 0;
}
