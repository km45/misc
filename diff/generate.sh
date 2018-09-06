#!/bin/bash

function main() {
  yarn run --silent dummyjson template.hbs > old.json

  cat old.json \
    | sed 's|\("id": \)\(1[0-9]\{2\},\)|\1-\2|g' \
    | sed '/"img1[0-9]\{2\}.png",/d' \
    | sed 's/"img3[0-9]\{2\}.png",/"hoge.png",/g' \
    > new.json
}

main "$@"
