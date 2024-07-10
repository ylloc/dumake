#pragma once

#include <vector>
#include <map>

#include <target.h>

class Executor {
private:
  std::vector<Target> targets;
  std::map<std::string, std::string> variables;

public:
};
