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
CFLAGS = -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lm -lrt
CSTANDARD = -std=c99
DEFFLAG =

INDENT_OPTS = -kr -prs -nut -bap -bad -br -cdb -sc
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE = out.dat
PLOT_OUTPUT_DIR = images

EXECUTABLES = utils.out insertionsort.out merge.out mergesort.out findk.out hybridsort.out main.out
PRG_OBJFILES = utils.o insertionSort.o merge.o mergeSort.o findK.o hybridSort.o main.o
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
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES)\ $(TEST_MODULE_OBJFILE)"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv *.o $(EXECUTABLES)
	@echo "Object files removed."

# Always clean the test module before compiling the rest.
$(TEST_MODULE_OBJFILE): $(TEST_MODULE_SRCFILE)
	@rm -rf $(TEST_MODULE_OBJFILE)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -c -o $@ $<

target utils: override DEFFLAG = -DM_UTILS_C
utils: $(TEST_MODULE_OBJFILE) utils.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_UTILS_C -o $@.out"
	@./validate.sh $@.out

target insertionsort: override DEFFLAG = -DM_INSERTIONSORT_C
insertionsort: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_INSERTIONSORT_C -o $@.out"
	@./validate.sh $@.out

target merge: override DEFFLAG = -DM_MERGE_C
merge: $(TEST_MODULE_OBJFILE) utils.o merge.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_MERGE_C -o $@.out"
	@./validate.sh $@.out

target mergesort: override DEFFLAG = -DM_MERGESORT_C
mergesort: $(TEST_MODULE_OBJFILE) utils.o merge.o mergeSort.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_MERGESORT_C -o $@.out"
	@./validate.sh $@.out

target findk: override DEFFLAG = -DM_FINDK_C
findk: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o merge.o mergeSort.o findK.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_FINDK_C -o $@.out"

target hybridsort: override DEFFLAG = -DM_HYBRIDSORT_C
hybridsort: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o merge.o mergeSort.o findK.o hybridSort.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_HYBRIDSORT_C -o $@.out"
	@./validate.sh $@.out

target main: override DEFFLAG = -DM_MAIN_C
main: $(PRG_OBJFILES)
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_MAIN_C -o $@.out"

plotfindk: findk
	@echo "Plotting findk..."
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./findk.out > $(PLOT_INPUT_FILE)
	@./plotFindK.sh $(PLOT_INPUT_FILE) > $(PLOT_OUTPUT_DIR)/findk.png
	@ rm $(PLOT_INPUT_FILE)
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/findk.png"
	@echo "Done."

plotcompare: main
	@echo "Plotting comparsion..."
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./main.out > $(PLOT_INPUT_FILE)
	@./plotCompare.sh $(PLOT_INPUT_FILE) > $(PLOT_OUTPUT_DIR)/comparison.png
	@ rm $(PLOT_INPUT_FILE)
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/comparison.png"
	@echo "Done."

