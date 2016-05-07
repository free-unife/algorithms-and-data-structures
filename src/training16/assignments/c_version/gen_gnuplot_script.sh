#!/bin/bash

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

# Script that generate a gnuplot script file.

inputPath="$1"
title="$2"
xLabel="$3"
yLabel="$4"
col0="$5"
col1="$6"
col2="$7"

################

style="lines"
terminalType="png medium"

cat <<-EOF
#!/usr/bin/gnuplot

#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

set terminal ${terminalType}
set key outside
set key right top
set title "${title}"
set xlabel "${xLabel}"
set ylabel "${yLabel}"

plot '${inputPath}' using "${col0}":"${col1}" with ${style}, '' using "${col0}":"${col2}" with ${style}

EOF


