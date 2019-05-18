#!/bin/sh

FILES="src/java/*.cpp test/java/*.cpp"
OUTPUT="./test.out"
COMPILER="g++"
LANGUAGE="c++1z"

$COMPILER -std=$LANGUAGE $FILES -o $OUTPUT -I src/

$OUTPUT

rm $OUTPUT
