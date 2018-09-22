#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

#include <nlohmann/json.hpp>  // used for printing

#include <cjson/cJSON.h>
#include <cjson/cJSON_Utils.h>

void Cjson() {
  std::ifstream ifs_old("old.json");
  std::ifstream ifs_new("new.json");

  std::string str_old = {std::istreambuf_iterator<char>(ifs_old),
                         std::istreambuf_iterator<char>()};
  std::string str_new = {std::istreambuf_iterator<char>(ifs_new),
                         std::istreambuf_iterator<char>()};

  auto jsonobj_old = std::unique_ptr<cJSON>(cJSON_Parse(str_old.c_str()));
  auto jsonobj_new = std::unique_ptr<cJSON>(cJSON_Parse(str_new.c_str()));

  std::cerr << "--- begin ---" << std::endl;
  auto jsonpatch =
      std::unique_ptr<cJSON>(cJSONUtils_GeneratePatchesCaseSensitive(
          jsonobj_old.get(), jsonobj_new.get()));
  std::cerr << "--- end ---" << std::endl;

  auto dumped =
      std::unique_ptr<char[]>(cJSON_PrintUnformatted(jsonpatch.get()));

  {
    nlohmann::json printer;
    std::istringstream iss(dumped.get());
    iss >> printer;
    std::cout << printer.dump(2);
  }

  cJSON_Delete(jsonobj_old.release());
}

int main() {
  Cjson();

  return 0;
}
