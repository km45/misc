#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

void JsonForModernCpp() {
  using json = nlohmann::json;

  std::ifstream ifs_old("../old.json");
  std::ifstream ifs_new("../new.json");

  json jsonobj_old;
  json jsonobj_new;

  ifs_old >> jsonobj_old;
  ifs_new >> jsonobj_new;

  const auto& jsonpatch = json::diff(jsonobj_old, jsonobj_new);

  std::cout << jsonpatch.dump(2);
}

int main() {
  JsonForModernCpp();

  return 0;
}
