#include <exception>
#include <iostream>
#include <string>

#include "library/calculator.h"

int main(int argc, char* argv[]) {
  try {
    std::string command;
    for (auto i = 1; i < argc; ++i) {
      command.append(argv[i]);
      if (i != argc - 1) {
        command.append(" ");
      }
    }

    const auto result_set = calculate(command);

    for (auto record : result_set) {
      std::cout << record << std::endl;
    }
  } catch (const std::exception& exception) {
    std::cerr << "Get exception " << exception.what() << std::endl;
    return -1;
  } catch (...) {
    std::cerr << "Get non-standard exception" << std::endl;
    return -1;
  }
  return 0;
}
