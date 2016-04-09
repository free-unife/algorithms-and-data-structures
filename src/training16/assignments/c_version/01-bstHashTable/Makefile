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


# macros
PRG_NAME = 01-htbst.o
PRG_OBJFILES = bst.o

CC = /usr/bin/gcc
BIN_DIR = /usr/bin
INSTALL = /usr/bin/install

CFLAGS = -Wall -Wextra -Wpedantic -Werror -march=native -O3
LIBS = -lm -lrt
CSTANDARD = -std=c99
MACRO_REQ =

INDENT_OPTS = -kr -prs -nut -bap -bad -br -cdb -sc
SPLINT_OPTS = -usereleased -compdef -preproc

# Targets

default : link # default target

all : link run

# compilation of single files, which keeps track of the changes of all header files (*.h) as well as the .c files
# @echo "$(CC) $< $(CFLAGS) $(CSTANDARD) $(MACRO_REQ)"
%.o: %.c *.h
	@$(CC) $(CFLAGS) $(CSTANDARD) $(MACRO_REQ) -c -o $@ $< # single object file compiling

# executables linking
link : $(PRG_OBJFILES) *.h
	@echo "Compiling ..."
	@echo "$(CC) -o $(PRG_NAME) $(CFLAGS) $(LIBS) $(CSTANDARD) $(MACRO_REQ)"
	@$(CC) $(CFLAGS) $(LIBS) $(CSTANDARD) $(MACRO_REQ) $(PRG_OBJFILES) -o $(PRG_NAME)
	@echo "Compiling terminated."

indent :
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" "$(PRG_OBJFILES)"
	@echo "Done."

validate :
	@echo "Validation..."
	@./validate.sh "$(PRG_NAME)"
	@echo "Done."

# Run verbose.
run :
	@echo "Running..."
	@./$(PRG_NAME)

runsilent :
	@echo "Running..."
	@./$(PRG_NAME) 2>&-

clean :
	@echo "Removing object files..."
	@rm -fv *.o $(PRG_NAME)
	@echo "Object files removed."

# to protect files with the following names, the .PHONY rule is used
.PHONY : all link install uninstall clean
