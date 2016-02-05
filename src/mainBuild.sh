#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


# Indent and compile files.

paths="$1"
output="$2"

# Set indent backup suffix.
export SIMPLE_BACKUP_SUFFIX=".indent.bak"
indentOptions="-kr -prs -nut"


# Check if indent executable exists.
which indent 1>/dev/null 2>/dev/null

if [ $? -eq 0 ]; then
    for file in $paths; do
        indent $indentOptions "$file"
        # Remove indent backup files.
        rm "${file}${SIMPLE_BACKUP_SUFFIX}"

        # Get header path (.h files).
        file="${file:0:(-2)}.h"
        indent $indentOptions "$file"
        rm "${file}${SIMPLE_BACKUP_SUFFIX}"
    done;

fi

# Compile.
gcc $paths -Wall -Wextra -Wpedantic -Werror \
-march=native -O0 -std=c90 -D_DEFAULT_SOURCE -o "$output"
