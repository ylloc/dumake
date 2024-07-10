#include <iostream>
#include <sstream>
#include <algorithm>

#include <parser.h>
#include <target.h>

void Parser::parse(std::istream& ss) {
  std::string line{};

  bool prev_line_was_target{false};

  while (std::getline(ss, line, '\n')) {
    std::cerr << line << std::endl;
    // remove spaces
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

    if (line.starts_with('$')) {
      auto eq = line.find('=');
      auto key = line.substr(1, eq - 1);
      auto value = line.substr(eq + 1, line.size() - eq - 1);
      variables.emplace(std::move(key), std::move(value));
    } else if (line.starts_with('<')) {
      auto pos_end = line.find('>');

      assert(pos_end != std::string::npos && "'>' expected");
      assert(pos_end == line.size() - 1 || line[pos_end + 1] == ':');
      Target target(std::move(line.substr(1, pos_end - 1)));

      // case empty dependencies
      if (pos_end == line.size() - 1) {
        targets.push_back(target);
        continue;
      } else {
        line = line.substr(pos_end + 3, line.size() - pos_end - 4);

        std::string dep_target{};
        std::stringstream stream(line);

        while (std::getline(stream, dep_target, ',')) {
          dep_target = dep_target.substr(1, dep_target.size() - 2);
          Target dep(dep_target);
          auto it = std::find(targets.begin(), targets.end(), dep);
          // TODO: reorder if it is possible
          assert(it != targets.end());
          target.add_dependence(&*it);
        }
      }
    } else {

    }
  }
}
