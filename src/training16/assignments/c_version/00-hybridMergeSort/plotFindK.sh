#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


path="$1"

title="Comparison between insertion sort and merge sort to find k"
xLabel="number of elements"
yLabel="time (s)"

col0="arraySize"
col1="insertionSortTime"
col2="mergeSortTime"

../plot.sh "$path" "$title" "$xLabel" "$yLabel" "$col0" "$col1" "$col2"

