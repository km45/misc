#!/bin/bash

function main() {
    yarn run jsondiffpatch ../old.json ../new.json
}

main "$@"
