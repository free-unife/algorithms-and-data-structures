#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


path="01-htlistbst.o"

title="Comparison between hash table implemented with chaining LISTs and BSTs"
xLabel="number of elements"
yLabel="time (s)"

style="linespoint"

col0="elements"
col1="list"
col2="bst"

gnuplotOptions="set terminal wxt persist; set title \""$title"\"; set xlabel \""$xLabel"\"; set ylabel \""$yLabel"\""
gnuplotColSpecifiers="using \"$col0\":\"$col1\" with $style, '' using \"$col0\":\"$col2\" with $style"

which gnuplot 1>/dev/null 2>/dev/null

[ $? -eq 0 ] \
&& gnuplot -e "$gnuplotOptions; plot '<./$path' $gnuplotColSpecifiers" \
|| printf "Install gnuplot\n"

