#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


path="$1"

title="Comparison between hash table implemented with chaining LISTs and BSTs"
xLabel="number of operations"
yLabel="time (s)"

col0="totalOperations"
col1="list"
col2="bst"

../plot.sh "$path" "$title" "$xLabel" "$yLabel" "$col0" "$col1" "$col2"

