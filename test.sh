#!/usr/bin/env bash

# todo: describe what this script does...

while inotifywait -e modify -r "./module" "./tests" ; do
    echo "[$0] waiting some time before running the command..."
    sleep 15

    make test
done
