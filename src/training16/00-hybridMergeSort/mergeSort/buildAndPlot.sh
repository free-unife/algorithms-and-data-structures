#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


paths="\
../utils/genRandomArray/genRandomArray.c \
../utils/measureRunningTime/measureRunningTime.c \
../utils/isArraySorted/isArraySorted.c \
main.c \
mergeSort.c"

output="mergeSort.o"
title="Merge Sort"
xLabel="Input size (# of elements)"
yLabel="Execution time (s)"


../mainBuild.sh "$paths" "$output" "$1" \
&& ../plot.sh "$output" "$title" "$xLabel" "$yLabel"

