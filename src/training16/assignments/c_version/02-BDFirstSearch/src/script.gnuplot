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
set title "Comparison between maximum stack and queue usage"
set xlabel "graph size"
set ylabel "max number of elements"

plot 'out.dat' using "size":"bfs" with points pointtype 5 pointsize 1, '' using "size":"dfs" with points pointtype 5 pointsize 1

#plot 'out.dat' using "size":"bfs" with points pointtype 5 pointsize 1
#plot 'out.dat' using "size":"dfs" with points pointtype 5 pointsize 1

