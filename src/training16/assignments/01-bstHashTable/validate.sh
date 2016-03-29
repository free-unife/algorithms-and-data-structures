#!/bin/bash

#
# validate.sh
#


path="$1"

{ [ $(./"$path" 2>&1 | grep ERR; echo $?) -eq 1 ] \
&& [ $(./"$path" 2>&-; echo $?) -eq 0 ]; } \
&& { printf "PASSED\n"; exit 0; } \
|| { printf "FAILED\n"; exit 1; }
