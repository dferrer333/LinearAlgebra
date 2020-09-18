#include <iostream>
#include <string>
#include "TestLogger.h"

void Test::Logger::print_success(
    std::string functionName, std::string fileName, int lineNumber) {
  Test::Logger::print_message(
      std::cerr, "[SUCCESS]", functionName, fileName, lineNumber);
}

void Test::Logger::print_failure(
    std::string functionName, std::string fileName, int lineNumber) {
  Test::Logger::print_message(
      std::cout, "[FAILURE]", functionName, fileName, lineNumber);
}

void Test::Logger::print_message(
    std::ostream &outputStream,
    std::string testTag,
    std::string &functionName,
    std::string &fileName,
    int lineNumber) {
  outputStream << testTag << " - FUNCTION: " << functionName << "; FILE: ";
  outputStream << fileName << "; LINE: " << lineNumber << ";\n";
}
