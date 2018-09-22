FROM gcc:latest

#
# JSON for Modern C++
#
RUN mkdir -p /usr/local/include/nlohmann && curl -fSL "https://github.com/nlohmann/json/releases/download/v3.2.0/json.hpp" > /usr/local/include/nlohmann/json.hpp

#
# cJSON
#
ENV CJSON_VERSION 1.7.7
RUN curl -fSL "https://github.com/DaveGamble/cJSON/archive/v${CJSON_VERSION}.tar.gz" | tar -zxv \
    && cd "cJSON-${CJSON_VERSION}" \
    && make all \
    && make install \
    && ldconfig \
    && cd / \
    && rm -rf "cJSON-${CJSON_VERSION}"

CMD ["tail", "-f", "/dev/null"]
