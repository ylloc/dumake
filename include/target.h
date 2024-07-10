#pragma once

#include <string>
#include <vector>

class Target {
private:
  std::vector<Target*> dependencies;
  std::vector<std::string> Commands;
  std::string target_name;

public:
  explicit Target(std::string name):
    target_name(std::move(name)) {}


  bool operator==(const Target& other) {
    return target_name == other.target_name;
  }

  void add_dependence(Target* target) {
    dependencies.push_back(target);
  }
};