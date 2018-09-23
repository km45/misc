#!/usr/bin/env python3

import json
import pprint

import deepdiff


def json2dict(filename: str) -> dict:
    with open(filename, 'r') as file:
        return json.load(file)
    return {}


def try_deepdiff(old: dict, new: dict) -> None:
    print(pprint.pprint(deepdiff.DeepDiff(old, new)))


def main():
    old: dict = json2dict('../old.json')
    new: dict = json2dict('../new.json')

    try_deepdiff(old, new)


if __name__ == '__main__':
    main()
