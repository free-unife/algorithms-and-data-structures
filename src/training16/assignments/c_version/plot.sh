#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


inputPath="$1"
title="$2"
xLabel="$3"
yLabel="$4"
col0="$5"
col1="$6"
col2="$7"

style="points pointtype 5 pointsize -1"
#terminalType="wxt persist"
terminalType="png medium"
keyProprieties="set key outside; set key right top"
gnuplotOptions="set terminal "$terminalType"; "$keyProprieties"; \
set title \""$title"\"; set xlabel \""$xLabel"\"; set ylabel \""$yLabel"\""

gnuplotColSpecifiers="using \"$col0\":\"$col1\" with $style, '' using \"$col0\":\"$col2\" with $style"

which gnuplot 1>/dev/null 2>/dev/null

[ $? -eq 0 ] \
&& gnuplot -e "$gnuplotOptions; plot 'out.dat' $gnuplotColSpecifiers" \
|| printf "Install gnuplot\n"

