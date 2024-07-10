#pragma once

#include <string>
#include <vector>

class Target {
private:
  std::string target_name;
  std::vector<Target*> dependencies;
  std::vector<std::string> Commands;
};