#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


path="$1"
gnuplotOptions="set terminal wxt persist"


printf "Plotting...\n"

which gnuplot 1>/dev/null 2>/dev/null

[ $? -eq 0 ] && gnuplot -e "$gnuplotOptions; plot '<./$path'" \
|| printf "Install gnuplot\n"

