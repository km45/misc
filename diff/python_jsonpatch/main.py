#!/usr/bin/env python3

import json

import jsonpatch


def json2dict(filename: str) -> dict:
    with open(filename, 'r') as file:
        return json.load(file)
    return {}


def try_jsonpatch(old: dict, new: dict) -> None:
    print(
        json.dumps(
            json.loads(
                jsonpatch.JsonPatch.from_diff(old, new).to_string()
            ),
            indent=2,
            sort_keys=True
        )
    )


def main():
    old: dict = json2dict('../old.json')
    new: dict = json2dict('../new.json')

    try_jsonpatch(old, new)


if __name__ == '__main__':
    main()
