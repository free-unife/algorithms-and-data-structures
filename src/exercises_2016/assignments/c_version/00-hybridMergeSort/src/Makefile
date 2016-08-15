#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

CC = /usr/bin/gcc
INCLUDE = -I../include
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -D_POSIX_C_SOURCE=199309L -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)
COMPILE = $(CC) $(INCLUDE) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS)

INDENT_OPTS = -nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 \
-cs -di2 -ndj -nfc1-nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE_FINDK = outfindk.dat
PLOT_INPUT_FILE_EXTRA = outextra.dat
PLOT_INPUT_FILE_COMPARE = outcomparison.dat
PLOT_OUTPUT_DIR = images
GNUPLOT_SCRIPT_FINDK = gnuplotfindk.script
GNUPLOT_SCRIPT_EXTRA = gnuplotextra.script
GNUPLOT_SCRIPT_COMPARE = gnuplotcomparison.script

EXECUTABLES = sort.out helper.out findk.out extra.out main.out
PRG_OBJFILES = utils.o sort.o helper.o findk.o extra.o main.o
TEST_MODULE_OBJFILE = test.o
TEST_MODULE_SRCFILE = test.c

FORCE_REBUILD_OBJFILES = $(TEST_MODULE_OBJFILE)

# To protect files with the following names, the .PHONY rule is used.
# This also enables us to force the TEST_MODULE_OBJFILE target.
.PHONY: default all clean indent $(EXECUTABLES) $(FORCE_REBUILD_OBJFILES)

default: plotcompare

%.o: %.c
	@$(COMPILE) -c -o $@ $<

$(TEST_MODULE_OBJFILE): $(TEST_MODULE_SRCFILE)
	@rm -rf $(TEST_MODULE_OBJFILE)
	@$(COMPILE) -c -o $@ $<

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES) \
$(TEST_MODULE_OBJFILE)"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv *.o *.out *.a
	@echo "Object files removed."

target sort: override DEFFLAG += -DSORT_C
sort: utils.o $(TEST_MODULE_OBJFILE) sort.o
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

target helper: override DEFFLAG += -DHELPER_C
helper: utils.o $(TEST_MODULE_OBJFILE) sort.o helper.o
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

target findk: override DEFFLAG += -DFINDK_C
findk: utils.o $(TEST_MODULE_OBJFILE) sort.o helper.o findk.o
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"

target prepareplotfindk: override DEFFLAG += -DFINDK_C
prepareplotfindk: findk
	@echo "Plotting..."
	@./findk.out > $(PLOT_INPUT_FILE_FINDK)

gengnuplotscriptfindk: prepareplotfindk
	@./gen_gnuplot_script.sh $(PLOT_INPUT_FILE_FINDK) \
"points pointtype 5 pointsize 1" \
"Comparison between insertion sort and merge sort to find k" \
"number of elements" "time (s)" "arraySize" \
"insertionSortTime" "mergeSortTime" > $(GNUPLOT_SCRIPT_FINDK)
	@chmod +x $(GNUPLOT_SCRIPT_FINDK)

plotfindk: gengnuplotscriptfindk
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT_FINDK) > $(PLOT_OUTPUT_DIR)/findk.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/findk.png"

extra: utils.o sort.o helper.o findk.o extra.o
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"

prepareplotextra: extra
	@echo "Plotting..."
	@./extra.out > $(PLOT_INPUT_FILE_EXTRA)

gengnuplotscriptextra: prepareplotextra
	@./gen_gnuplot_script.sh $(PLOT_INPUT_FILE_EXTRA) \
"points pointtype 5 pointsize 1" \
"Comparison between merge and hybrid sort for K = {15,20,35,50}" \
"K" "time (s)" "K" "mergeSortTime" "hybridSortTime" \
> $(GNUPLOT_SCRIPT_EXTRA)
	@chmod +x $(GNUPLOT_SCRIPT_EXTRA)

plotextra: gengnuplotscriptextra
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT_EXTRA) > $(PLOT_OUTPUT_DIR)/extra.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/extra.png"

main: utils.o sort.o helper.o findk.o main.o
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"

prepareplotcompare: main
	@echo "Plotting..."
	@./main.out > $(PLOT_INPUT_FILE_COMPARE)

gengnuplotscriptcompare: prepareplotcompare
	@./gen_gnuplot_script.sh $(PLOT_INPUT_FILE_COMPARE) \
"points pointtype 5 pointsize 1" \
"Comparison between hybrid sort and merge sort related to K" \
"K" "time (s)" "K" "mergeSortTime" "hybridSortTime" \
> $(GNUPLOT_SCRIPT_COMPARE)
	@chmod +x $(GNUPLOT_SCRIPT_COMPARE)

plotcompare: gengnuplotscriptcompare
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT_COMPARE) > $(PLOT_OUTPUT_DIR)/comparison.png
	@echo "Plot results have been written in \
$(PLOT_OUTPUT_DIR)/comparison.png"

