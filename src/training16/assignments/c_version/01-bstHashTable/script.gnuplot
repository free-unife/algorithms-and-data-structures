#!/usr/bin/gnuplot

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

set terminal png medium
set key outside
set key right top
set title "Comparison between hash table implemented with chaining LISTs and BSTs"
set xlabel "number of operations"
set ylabel "time (s)"

plot 'out.dat' using "totalOperations":"list" with lines, '' using "totalOperations":"bst" with lines

