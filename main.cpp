#include <iostream>
#include <executor.h>
#include <parser.h>
#include <fstream>

int main(int argc, char** argv) {
  Parser parser{};
  std::ifstream fs("../tests/example.dk");
  assert(fs);
  parser.parse(fs);
}