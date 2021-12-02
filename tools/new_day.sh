#!/bin/env bash

DAY=$1

# Copy template to new day
cp -rv ../template/day00 ../day$DAY

# Replace all occurances of 00 to new date
find ../day$DAY -type f -exec sed -i "s/00/$DAY/g" {} \;