#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
#                  Danny Lessio
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#


# Macros.
CC = /usr/bin/gcc

DEPS = globalDefines.h
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lm -lrt
CSTANDARD = -std=c99
DEFFLAG =

INDENT_OPTS = -nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 -cs -di2 -ndj -nfc1-nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE = out.dat
PLOT_OUTPUT_DIR = images

EXECUTABLES = utils.out adt.out bst.out
PRG_OBJFILES = utils.o adt.o
TEST_MODULE_OBJFILE = tests.o
TEST_MODULE_SRCFILE = tests.c

# To protect files with the following names, the .PHONY rule is used.
# This also enables us to force the TEST_MODULE_OBJFILE target.
.PHONY: default all clean indent $(EXECUTABLES) $(TEST_MODULE_OBJFILE)

default: main

all: main plotcompare

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -c -o $@ $<

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES) $(TEST_MODULE_OBJFILE) $(DEPS)"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out
	@echo "Object files removed."

# Always clean the test module before compiling the rest.
$(TEST_MODULE_OBJFILE): $(TEST_MODULE_SRCFILE)
	@rm -rf $(TEST_MODULE_OBJFILE)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -c -o $@ $<

target utils: override DEFFLAG = -DM_UTILS_C
utils: $(TEST_MODULE_OBJFILE) utils.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_UTILS_C -o $@.out"
	#@./validate.sh $@.out

target adt: override DEFFLAG = -DM_ADT_C
adt: $(TEST_MODULE_OBJFILE) utils.o adt.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_ADT_C -o $@.out"
	#@./validate.sh $@.out

target bst: override DEFFLAG = -DM_BST_C
bst: $(TEST_MODULE_OBJFILE) utils.o adt.o bst.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_BST_C -o $@.out"
	#@./validate.sh $@.out

doxygen:
	@doxygen doxy.conf

doxygenlatex: doxygen
	@cd latex; make pdf; mv refman.pdf ../.; cd ..

cleandoxygen:
	@rm -rf html latex refman.pdf

cleanall: clean cleandoxygen
