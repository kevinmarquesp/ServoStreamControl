#!/usr/bin/env bash

# todo: describe what this script does...

SKETCH_NAME="ServoStreamControl"

while inotifywait -e modify -r "./$SKETCH_NAME/src" ; do
    echo "[$0] waiting some time before running the command..."
    sleep 15

    make test
done