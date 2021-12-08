#!/bin/env bash

DAY=$1

# Make new directory
# Copy template to new day
mkdir ../day$DAY &&\
    cp -rv ../template/day00/* ../day$DAY/ &&\
    find ../day$DAY -type f -exec sed -i "s/00/$DAY/g" {} \;

