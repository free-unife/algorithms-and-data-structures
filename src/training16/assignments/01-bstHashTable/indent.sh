#!/bin/bash

#
# indent.sh
#


indentOptions="$1"
splintOptions="$2"
paths="$3"

# Set indent backup suffix.
export SIMPLE_BACKUP_SUFFIX=".indent.bak"

# Check if indent and splint executable exists.
which indent splint 1>/dev/null 2>/dev/null

if [ $? -eq 0 ]; then
    for file in $paths; do
        file="${file:0:(-2)}.c"
        splint $splintOptions "$file"
        indent $indentOptions "$file"
        # Remove indent backup files.
        rm "${file}${SIMPLE_BACKUP_SUFFIX}"

        # Get header path (.h files).
        file="${file:0:(-2)}.h"
        [ -f "$file" ] \
            && indent $indentOptions "$file" \
            && rm "${file}${SIMPLE_BACKUP_SUFFIX}"
    done;
fi

