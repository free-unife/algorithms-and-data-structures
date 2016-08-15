#!/bin/sh

#
# runTests.sh
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

{ make list_base TEST_TYPE=SIMPLE_TEST \
&& make list_extended TEST_TYPE=SIMPLE_TEST \
&& make stack TEST_TYPE=SIMPLE_TEST \
&& make queue TEST_TYPE=SIMPLE_TEST \
&& make list TEST_TYPE=SIMPLE_TEST \
&& make api TEST_TYPE=SIMPLE_TEST \
&& make clean; } \
&& { make list_extended TEST_TYPE=EXTENDED_TEST \
&& make stack TEST_TYPE=EXTENDED_TEST \
&& make queue TEST_TYPE=EXTENDED_TEST \
&& make clean; }


