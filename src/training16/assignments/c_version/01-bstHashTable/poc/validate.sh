#!/bin/bash

#
# validate.sh
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


path="$1"

printf "\nValidation status: "
{ [ -x "$path" ] && [ $(./"$path" 2>&1 | grep -c ERR) -eq 0 ] \
&& [ $(./"$path" 2>&-; echo $?) -eq 0 ]; } \
&& { printf "PASSED\n"; exit 0; } \
|| { printf "FAILED\n"; exit 1; }
