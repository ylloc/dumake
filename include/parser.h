#pragma once

#include <istream>
#include <map>

#include <target.h>

class Parser {
public:
  void parse(std::istream& ss);

private:
  std::map<std::string, std::string> variables;
  std::vector<Target> targets;
};

