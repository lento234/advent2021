#!/bin/env bash

# Fetch personal leaderboard stats
# convert from HTML to pandoc
# delete all unwanted lines and HTML tags containing {}
# write to README.md

sed -i '/## Scoreboard/,//d' ../README.md

echo -e "## Scoreboard" >> ../README.md

curl -s -H "Cookie: session=$(cat .cookie)" https://adventofcode.com/2021/leaderboard/self \
    | pandoc -f html -t markdown \
    | sed -e '/<div>/,/otherwise./d' -e '/:::/,//d' \
    >> ../README.md
