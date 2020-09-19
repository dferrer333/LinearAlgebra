#ifndef TEST_LOGGER_H
#define TEST_LOGGER_H

#include <iostream>
#include <string>

namespace Test {
  namespace Logger {
    void print_success(
        std::string functionName,
        std::string fileName,
        int lineNumber);
    void print_failure(
        std::string functionName,
        std::string fileName,
        int lineNumber);
    void print_message(
        std::ostream &outputStream,
        std::string testTag,
        std::string &functionName,
        std::string &fileName,
        int lineNumber);
  }
}

#endif
