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
style="$2"
title="$3"
xLabel="$4"
yLabel="$5"
col0="$6"
col1="$7"
col2="$8"

################

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

#plot '${inputPath}' using "${col0}":"${col1}" with ${style}
#plot '${inputPath}' using "${col0}":"${col2}" with ${style}

EOF


