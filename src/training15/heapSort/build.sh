#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


paths="main.c heapSort.c ../printArray/printArray.c"
output="heapSort.o"

../mainBuild.sh "$paths" "$output" "$1"
