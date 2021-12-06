#!/bin/env bash

DAY=$1

# Fetch input data of day $DAY from adventofcode.com using curl and session cookie stored in .cookie file
curl -s -H "Cookie: session=$(cat .cookie)" https://adventofcode.com/2021/day/${DAY#0}/input > ../day$DAY/input.txt

