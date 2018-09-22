#include <fstream>
#include <iostream>

#include <jsoncons/json.hpp>
#include <jsoncons/json_serializing_options.hpp>
#include <jsoncons_ext/jsonpatch/jsonpatch.hpp>

void Jsoncons() {
  using jsoncons::json;

  std::ifstream ifs_old("../old.json");
  std::ifstream ifs_new("../new.json");

  json jsonobj_old;
  json jsonobj_new;

  ifs_old >> jsonobj_old;
  ifs_new >> jsonobj_new;

  const auto& jsonpatch =
      jsoncons::jsonpatch::from_diff(jsonobj_old, jsonobj_new);

  jsoncons::json_serializing_options options;
  options.indent(2);
  options.object_array_split_lines(jsoncons::line_split_kind::multi_line);

  std::cout << pretty_print(jsonpatch, options) << std::endl;
}

int main() {
  Jsoncons();

  return 0;
}
