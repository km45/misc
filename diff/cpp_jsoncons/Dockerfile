FROM gcc:latest

#
# jsoncons
#
ENV JSONCONS_VERSION 0.109.0
RUN curl -fSL "https://github.com/danielaparker/jsoncons/archive/v${JSONCONS_VERSION}.tar.gz" | tar -zxv \
    && cp -pr "jsoncons-${JSONCONS_VERSION}/include/jsoncons" /usr/local/include/ \
    && cp -pr "jsoncons-${JSONCONS_VERSION}/include/jsoncons_ext" /usr/local/include/ \
    && rm -rf "jsoncons-${JSONCONS_VERSION}"

CMD ["tail", "-f", "/dev/null"]
