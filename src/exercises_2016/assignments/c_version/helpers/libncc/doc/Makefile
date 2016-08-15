#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

default: doc

clean:
	@echo "Removing object files..."
	@rm -fv *.pdf
	@echo "Object files removed."

doc:
	@texi2pdf --build=clean libncc.texi

.PHONY: default doc

