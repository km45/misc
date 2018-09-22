FROM gcc:latest

#
# JSON for Modern C++
#
RUN mkdir -p /usr/local/include/nlohmann && curl -fSL "https://github.com/nlohmann/json/releases/download/v3.2.0/json.hpp" > /usr/local/include/nlohmann/json.hpp

CMD ["tail", "-f", "/dev/null"]
