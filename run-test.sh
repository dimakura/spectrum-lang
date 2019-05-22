#!/bin/sh

FILES="src/java/ast/identifier.cpp src/java/ast/type.cpp test/java/ast/type_test.cpp"
OUTPUT="./test.out"
COMPILER="g++"
LANGUAGE="c++1z"

$COMPILER -std=$LANGUAGE $FILES -o $OUTPUT -I src/

$OUTPUT

rm $OUTPUT
