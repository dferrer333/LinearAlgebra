#include <iostream>
#include <string>

namespace Test {
  namespace Logger {
    void print_success(
        std::string fileName,
        std::string functionName,
        std::string lineNumber);
    void print_failure(
        std::string fileName,
        std::string functionName,
        std::string lineNumber);
    void print_message(
        std::ostream &outputStream,
        std::string testTag,
        std::string &functionName,
        std::string &fileName,
        std::string &lineNumber);
  }
}

void Test::Logger::print_success(
    std::string functionName, std::string fileName, std::string lineNumber) {
  Test::Logger::print_message(
      std::cerr, "[SUCCESS]", functionName, fileName, lineNumber);
}

void Test::Logger::print_failure(
    std::string functionName, std::string fileName, std::string lineNumber) {
  Test::Logger::print_message(
      std::cout, "[FAILURE]", functionName, fileName, lineNumber);
}

void Test::Logger::print_message(
    std::ostream &outputStream,
    std::string testTag,
    std::string &functionName,
    std::string &fileName,
    std::string &lineNumber) {
  outputStream << testTag << " - FUNCTION: " << functionName << "; FILE: ";
  outputStream << fileName << "; LINE: " << lineNumber << ";\n";
}
