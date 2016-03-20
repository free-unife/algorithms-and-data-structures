#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


paths="\
hash.c \
main.c"

output="hash.o"
title="Hybrid merge sort and Merge sort comparison"
xLabel="Input size (# of elements)"
yLabel="Diff execution time (hybrid - merge) (s)"


../mainBuild.sh "$paths" "$output" "$1" \
&& ./hash.o
#&& ../plot.sh "$output" "$title" "$xLabel" "$yLabel"

