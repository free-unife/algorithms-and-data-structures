#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

# Structure name.
TYPE=struct\ example
CC = /usr/bin/gcc
INCLUDE = -I../include
# Library include directory path.
INCLUDELIB = -I../../include
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)

default: example

.PHONY: default libncc example example.out

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out *.a
	@echo "Object files removed."

%.o: %.c
	@$(CC) $(INCLUDE) $(INCLUDELIB) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -c -o $@ $<

libncc:
	@$(MAKE) -C ../../
	@mv ../../$@.a .

example: example.o libncc
	@$(CC) $(INCLUDE) $(INCLUDELIB) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out example.o libncc.a
	@echo "$(CC) $(INCLUDE) $(INCLUDELIB) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out example.o libncc.a"


