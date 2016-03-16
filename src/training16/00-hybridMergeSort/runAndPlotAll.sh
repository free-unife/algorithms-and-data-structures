#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


paths="insertionSort mergeSort"
buildAndPlotPath="./buildAndPlot.sh"

for cpath in $paths; do
    echo $cpath
    (cd "$cpath" && $buildAndPlotPath && cd "$OLDPWD") &
done
