#!/bin/bash

#
# indent.sh
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


indentOptions="$1"
paths="$2"

# Set indent backup suffix.
export SIMPLE_BACKUP_SUFFIX=".indent.bak"

# Check if indent and splint executable exists.
which indent 1>/dev/null 2>/dev/null

if [ $? -eq 0 ]; then
    for file in $paths; do
        file="${file:0:(-2)}.c"
        indent $indentOptions "$file"
        # Remove indent backup files.
        rm -rf "${file}${SIMPLE_BACKUP_SUFFIX}"

        # Get header path (.h files).
        file="${file:0:(-2)}.h"
        [ -f "$file" ] \
&& { indent $indentOptions "$file"; rm "${file}${SIMPLE_BACKUP_SUFFIX}"; }
    done;
fi

