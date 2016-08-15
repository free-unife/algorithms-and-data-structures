#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

# Recipe
# make libncc TYPE=<native C type || struct\ smt>

TYPE=int

default: libncc

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out *.a
	@echo "Object files removed."

libncc:
	@$(MAKE) -C src
	@mv src/$@.a .
	@$(MAKE) -C src clean

doc:
	@$(MAKE) -C $@
	@mv $@/libncc.pdf .

example:
	@$(MAKE) -C $@/src
	@mv $@/src/$@.out .
	@$(MAKE) -C $@/src clean

.PHONY: default libncc doc example

