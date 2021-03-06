#!/bin/env bash

DAY=$1

echo -e "# Day $DAY\n" > ../day$DAY/README.md

# Fetch day $DAY using curl and cookie
# convert from HTML to pandoc
# delete all unwanted lines and HTML tags containing {}
# write to README.md
curl -s -H "Cookie: session=$(cat .cookie)" https://adventofcode.com/2021/day/${DAY#0} \
    | pandoc -f html -t markdown \
    | sed -e '/<div>/,/::: {role="main"}/d' -e '/Both parts of this puzzle are complete!/,//d' -e 's/{[^{}]*}//g' \
    >> ../day$DAY/README.md

