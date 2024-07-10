#pragma once

#include <istream>
#include <map>

class Parser {
public:
  void parse(std::istream ss);

private:
  std::map<std::string, std::string> variables{};
};

