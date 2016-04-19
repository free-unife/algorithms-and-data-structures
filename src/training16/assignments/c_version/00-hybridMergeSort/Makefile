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
PRG_NAME = 00-hybridMergeComp.o
PRG_OBJFILES = utils.o insertionSort.o merge.o mergeSort.o findK.o hybridSort.o main.c

CC = /usr/bin/gcc
BIN_DIR = /usr/bin
INSTALL = /usr/bin/install

CFLAGS = -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lm -lrt
CSTANDARD = -std=c99
MACRO_REQ =

INDENT_OPTS = -kr -prs -nut -bap -bad -br -cdb -sc
SPLINT_OPTS = -usereleased -compdef -preproc

PLOT_INPUT_FILE = out.dat
PLOT_OUTPUT_DIR = images

# Targets

default : link # default target

all : link run

# compilation of single files, which keeps track of the changes of all header files (*.h) as well as the .c files
# @echo "$(CC) $< $(CFLAGS) $(CSTANDARD) $(MACRO_REQ)"
%.o: %.c *.h
	@$(CC) $(CFLAGS) $(CSTANDARD) $(MACRO_REQ) -c -o $@ $< # single object file compiling

# executables linking
link: $(PRG_OBJFILES) *.h
	@echo "Compiling ..."
	@echo "$(CC) -o $(PRG_NAME) $(CFLAGS) $(LIBS) $(CSTANDARD) $(MACRO_REQ)"
	@$(CC) $(CFLAGS) $(LIBS) $(CSTANDARD) $(MACRO_REQ) $(PRG_OBJFILES) -o $(PRG_NAME)
	@echo "Compilation terminated."

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES)"
	@echo "Done."

validate:
	@echo "Validation..."
	@./validate.sh "$(PRG_NAME)"
	@echo "Done."

# Run verbose.
run:
	@echo "Running..."
	@./$(PRG_NAME)
	@echo "Done."

runsilent:
	@echo "Running..."
	@./$(PRG_NAME) 2>&-
	@echo "Done."

findk:
	@echo "Plotting findk..."
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(PRG_NAME) > $(PLOT_INPUT_FILE)
	@./plotFindK.sh $(PLOT_INPUT_FILE) > $(PLOT_OUTPUT_DIR)/findk.png
	@ rm $(PLOT_INPUT_FILE)
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/findk.png"
	@echo "Done."

compare:
	@echo "Plotting comparsion..."
	@mkdir -p $(PLOT_OUTPUT_DIR)
	@./$(PRG_NAME) > $(PLOT_INPUT_FILE)
	@./plotComparison.sh $(PLOT_INPUT_FILE) > $(PLOT_OUTPUT_DIR)/comparison.png
	@ rm $(PLOT_INPUT_FILE)
	@echo "Plot results have been written in $(PLOT_OUTPUT_DIR)/comparison.png"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv *.o $(PRG_NAME)
	@echo "Object files removed."

# to protect files with the following names, the .PHONY rule is used
.PHONY: all link install uninstall clean
