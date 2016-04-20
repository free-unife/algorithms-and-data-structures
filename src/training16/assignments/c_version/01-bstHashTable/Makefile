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

DEPS = definedModules.h globalDefines.h
CFLAGS = -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lm -lrt
CSTANDARD = -std=c99
DEFFLAG =

INDENT_OPTS = -kr -prs -nut -bap -bad -br -cdb -sc
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE = out.dat
PLOT_OUTPUT_DIR = images

EXECUTABLES = list.out bst.out listht.out bstht.out hash.out htlist.out htbst.out main.out
PRG_OBJFILES = list.o bst.o listht.o bstht.o hash.o htlist.o htbst.o main.o

# Targets
default : main # default target

all : main plot

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) $(DEFFLAG) -c -o $@ $<

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES)"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv *.o $(EXECUTABLES)
	@echo "Object files removed."

target bst: override DEFFLAG = -DM_BSTMAIN_C
bst: bst.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_BSTMAIN_C -o $@.out"
	@./validate.sh $@.out

target bstht: override DEFFLAG = -DM_BSTHTMAIN_C
bstht: bst.o bstht.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_BSTHTMAIN_C -o $@.out"
	@./validate.sh $@.out

target htbst: override DEFFLAG = -DM_HTBSTMAIN_C
htbst: bst.o bstht.o hash.o htbst.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_BSTHTMAIN_C -o $@.out"
	@./validate.sh $@.out

target list: override DEFFLAG = -DM_LISTMAIN_C
list: list.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_LISTMAIN_C -o $@.out"
	@./validate.sh $@.out

target listht: override DEFFLAG = -DM_LISTHTMAIN_C
listht: list.o listht.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_LISTHTMAIN_C -o $@.out"
	@./validate.sh $@.out

target htlist: override DEFFLAG = -DM_HTLISTMAIN_C
htlist: list.o listht.o hash.o htlist.o
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -DM_HTLISTMAIN_C -o $@.out"
	@./validate.sh $@.out

main: $(PRG_OBJFILES)
	@$(CC) -o $@.out $^
	@echo "$(CC) $(CFLAGS) $(CSTANDARD) $(LIBS) -o $@.out"

plot: main
	@echo "Plotting..."
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./main.out > $(PLOT_INPUT_FILE)
	@./plot.sh $(PLOT_INPUT_FILE) > $(PLOT_OUTPUT_DIR)/plot.png
	@ rm $(PLOT_INPUT_FILE)
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/plot.png"
	@echo "Done."

# to protect files with the following names, the .PHONY rule is used
.PHONY: default all clean indent $(EXECUTABLES)
