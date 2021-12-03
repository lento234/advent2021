#!/bin/env bash

DAY=$1

# Fetch day $DAY and append to README.md using pandoc
curl -s https://adventofcode.com/2021/day/${DAY#0} | pandoc -f html -t markdown >> ../day$DAY/README.md