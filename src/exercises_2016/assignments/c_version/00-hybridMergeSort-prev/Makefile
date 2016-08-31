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

# INDENT_OPTS = -kr -prs -nut -bap -bad -br -cdb -sc
INDENT_OPTS = -nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 -cs -di2 -ndj -nfc1-nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE_FINDK = outfindk.dat
PLOT_INPUT_FILE_COMPARE = outcomparison.dat
PLOT_OUTPUT_DIR = images
GNUPLOT_SCRIPT_FINDK = gnuplotfindk.script
GNUPLOT_SCRIPT_COMPARE = gnuplotcomparison.script

EXECUTABLES = utils.out insertionsort.out merge.out mergesort.out findk.out hybridsort.out main.out
PRG_OBJFILES = utils.o insertionSort.o merge.o mergeSort.o findK.o hybridSort.o main.o
TEST_MODULE_OBJFILE = tests.o
TEST_MODULE_SRCFILE = tests.c

# To protect files with the following names, the .PHONY rule is used.
# This also enables us to force the TEST_MODULE_OBJFILE target.
.PHONY: default all clean indent $(EXECUTABLES) $(TEST_MODULE_OBJFILE)

default: plotcompare

all: main plotcompare

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -c -o $@ $<

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES) $(TEST_MODULE_OBJFILE) $(DEPS)"
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
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"
	@./validate.sh $@.out

target insertionsort: override DEFFLAG = -DM_INSERTIONSORT_C
insertionsort: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"
	@./validate.sh $@.out

target merge: override DEFFLAG = -DM_MERGE_C
merge: $(TEST_MODULE_OBJFILE) utils.o merge.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"
	@./validate.sh $@.out

target mergesort: override DEFFLAG = -DM_MERGESORT_C
mergesort: $(TEST_MODULE_OBJFILE) utils.o merge.o mergeSort.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"
	@./validate.sh $@.out

target findk: override DEFFLAG = -DM_FINDK_C
findk: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o merge.o mergeSort.o findK.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"

target hybridsort: override DEFFLAG = -DM_HYBRIDSORT_C
hybridsort: $(TEST_MODULE_OBJFILE) utils.o insertionSort.o merge.o mergeSort.o findK.o hybridSort.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"
	@./validate.sh $@.out

target main: override DEFFLAG = -DM_MAIN_C
main: $(PRG_OBJFILES)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -o $@.out"

target prepareplotfindk: override DEFFLAG = -DM_FINDK_C
prepareplotfindk: findk
	@echo "Plotting..."
	@./findk.out > $(PLOT_INPUT_FILE_FINDK)

gengnuplotscriptfindk: prepareplotfindk
	@./gen_gnuplot_script.sh $(PLOT_INPUT_FILE_FINDK) "points pointtype 5 pointsize 1" "Comparison between insertion sort and merge sort to find k" "number of elements" "time (s)" "arraySize" "insertionSortTime" "mergeSortTime" > $(GNUPLOT_SCRIPT_FINDK)
	@chmod +x $(GNUPLOT_SCRIPT_FINDK)

plotfindk: gengnuplotscriptfindk
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT_FINDK) > $(PLOT_OUTPUT_DIR)/findk.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/findk.png"

prepareplotcompare: main
	@echo "Plotting..."
	@./main.out > $(PLOT_INPUT_FILE_COMPARE)

gengnuplotscriptcompare: prepareplotcompare
	@./gen_gnuplot_script.sh $(PLOT_INPUT_FILE_COMPARE) "points pointtype 5 pointsize 1" "Comparison between hybrid sort and merge sort related to K" "K" "time (s)" "K" "mergeSortTime" "hybridSortTime"> $(GNUPLOT_SCRIPT_COMPARE)
	@chmod +x $(GNUPLOT_SCRIPT_COMPARE)

plotcompare: gengnuplotscriptcompare
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT_COMPARE) > $(PLOT_OUTPUT_DIR)/comparison.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/comparison.png"

