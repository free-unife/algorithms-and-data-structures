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
GNUPLOT_SCRIPT = script.gnuplot

EXECUTABLES = utils.out poc.out vertex.out vertexList.out graph.out
PRG_OBJFILES = utils.o poc.o vertex.o vertexList.o graph.o
TEST_MODULE_OBJFILE = tests.o
TEST_MODULE_SRCFILE = tests.c

FORCE_REBUILD_OBJFILES = $(TEST_MODULE_OBJFILE)

# To protect files with the following names, the .PHONY rule is used.
# This also enables us to force the TEST_MODULE_OBJFILE target.
.PHONY: default all clean indent $(EXECUTABLES) $(FORCE_REBUILD_OBJFILES)

default: main

all: main plotcompare

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -c -o $@ $<

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
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -c -o $@ $<

target utils: override DEFFLAG = -DM_UTILS_C
utils: $(TEST_MODULE_OBJFILE) utils.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target poc: override DEFFLAG = -DM_POC_C
poc: $(TEST_MODULE_OBJFILE) utils.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target vertex: override DEFFLAG = -DM_VERTEX_C
vertex: $(TEST_MODULE_OBJFILE) utils.o vertex.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target vertexlist: override DEFFLAG = -DM_VERTEXLIST_C
vertexlist: $(TEST_MODULE_OBJFILE) utils.o vertex.o vertexList.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target graph: override DEFFLAG = -DM_GRAPH_C
graph: $(TEST_MODULE_OBJFILE) utils.o vertex.o vertexList.o graph.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

main: $(TEST_MODULE_OBJFILE) utils.o node.o bst.o list.o ht.o main.o
	@$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(DEFFLAG) $(LIBS) -o $@.out"

prepareplot: main
	@echo "Plotting..."
	@./main.out > $(PLOT_INPUT_FILE)

gengnuplotscript: prepareplot
	@../gen_gnuplot_script.sh "out.dat" "lines" "Comparison between hash table implemented with chaining LISTs and BSTs" "number of operations" "time (s)" "totalOperations" "list" "bst" > $(GNUPLOT_SCRIPT)
	@chmod +x $(GNUPLOT_SCRIPT)

plot: gengnuplotscript
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT) > $(PLOT_OUTPUT_DIR)/plot.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/plot.png"
