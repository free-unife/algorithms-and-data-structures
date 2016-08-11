#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

TYPE = struct\ VertexObject

CC = /usr/bin/gcc
INCLUDE = -I../include
INCLUDELIB = -I../../libncc/include
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -D_POSIX_C_SOURCE=199309L -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)
COMPILE = 	@$(CC) $(INCLUDE) $(INCLUDELIB) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS)

INDENT_OPTS = -nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 \
-cs -di2 -ndj -nfc1-nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE = out.dat
PLOT_OUTPUT_DIR = images
GNUPLOT_SCRIPT = script.gnuplot

EXECUTABLES = libncc.a vertex.out graph.out visit.out helper.out main.out
PRG_OBJFILES = libncc.a utils.o vertex.o graph.o visit.o helper.o main.o
TEST_MODULE_OBJFILE = test.o
TEST_MODULE_SRCFILE = test.c

FORCE_REBUILD_OBJFILES = $(TEST_MODULE_OBJFILE)

# To protect files with the following names, the .PHONY rule is used.
# This also enables us to force the TEST_MODULE_OBJFILE target.
.PHONY: default all clean indent $(EXECUTABLES) $(FORCE_REBUILD_OBJFILES)

default: main

%.o: %.c ../include/main.h
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

libncc.a:
	@$(MAKE) -C ../../libncc
	@mv ../../libncc/$@ .

target vertex: override DEFFLAG += -DVERTEX_C
vertex: utils.o $(TEST_MODULE_OBJFILE) vertex.o libncc.a
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

target graph: override DEFFLAG += -DGRAPH_C
graph: utils.o $(TEST_MODULE_OBJFILE) vertex.o graph.o libncc.a
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

target visit: override DEFFLAG += -DVISIT_C
visit: utils.o $(TEST_MODULE_OBJFILE) vertex.o graph.o visit.o libncc.a
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

target helper: override DEFFLAG += -DHELPER_C
helper: utils.o $(TEST_MODULE_OBJFILE) vertex.o graph.o helper.o libncc.a
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"
	@./validate.sh $@.out

main: utils.o vertex.o graph.o visit.o helper.o main.o libncc.a
	@$(COMPILE) -o $@.out $^
	@echo "$(COMPILE) -o $@.out $^"

prepareplot: main
	@echo "Plotting..."
	@./main.out > $(PLOT_INPUT_FILE)

gengnuplotscript: prepareplot
	@./gen_gnuplot_script.sh "out.dat" "points pointtype 5 pointsize 1" \
"Comparison between maximum stack and queue usage" \
"graph size" "max number of elements" "size" \
"bfs" "dfs" > $(GNUPLOT_SCRIPT)
	@chmod +x $(GNUPLOT_SCRIPT)

plot: gengnuplotscript
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(GNUPLOT_SCRIPT) > $(PLOT_OUTPUT_DIR)/plot.png
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/plot.png"

