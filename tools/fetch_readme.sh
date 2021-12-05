#!/bin/env bash

DAY=$1

# Fetch day $DAY and append to README.md using pandoc
curl -s -H "Cookie: session=$(cat .cookie)" https://adventofcode.com/2021/day/${DAY#0} | pandoc -f html -t markdown | sed '/<div>/,/::: {role="main"}/d' | sed '/At this point/,//d' >> ../day$DAY/README.md