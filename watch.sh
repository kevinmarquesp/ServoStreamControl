#!/usr/bin/env bash

test inotifywait || exit 1

# This script keeps watching the specified files below to see if theyre saved,
# after each save, it will rerun all the test suit cases to ensure that the
# changes that was made on the files doesn't break anything. It's meant to be
# ran in the background all the time while you are coding.

SKETCH_NAME="ServoStreamControl"
SKETCH_MODULES="${SKETCH_NAME}/src"
TESTS_DIR="tests"

while inotifywait -e modify -r "${SKETCH_MODULES}" "${TESTS_DIR}" ; do
    echo "[$0] waiting some time before running the command..."
    sleep 15
    clear
    make test-all
done
