#!/usr/bin/make -f

#
# Makefile
#
# Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See the LICENSE file for more details.
#

# variable TYPE must be a single word. This can be specified from command line.
TYPE=int

TEST_ITERATIONS = 32
# Choose between SIMPLE_TEST and EXTENDED_TEST
TEST_TYPE = SIMPLE_TEST

CC = /usr/bin/gcc
INCLUDEDIR = -I../include
CFLAGS = -g -Wall -Wextra -Wpedantic -Werror -march=native -O0
LIBS = -lrt
CSTANDARD = -std=c99
DEFFLAG = -DelementObject=$(TYPE)

INDENT_OPTS = -nbad -bap -nbc -bbo -bl -bli2 -bls -ncdb -nce -cp1 \
-cs -di2 -ndj -nfc1-nfca -hnl -i2 -ip5 -lp -pcs -psl -nsc -nsob

PRIVATE = private
ADT = adt
PUBLIC = public

EXECUTABLES = $(PRIVATE)/utils.out  $(PRIVATE)/list_base.out \
$(PRIVATE)/list_extended.out  $(PRIVATE)/list_extras.out \
$(API)/stack.out $(API)/queue.out $(API)/list.out \
$(PUBLIC)/libncc.out
PRG_OBJFILES = $(PRIVATE)/utils.o  $(PRIVATE)/list_base.o \
$(PRIVATE)/list_extended.o $(PRIVATE)/list_extras.o \
$(ADT)/stack.o $(ADT)/queue.o $(ADT)/list.o $(PUBLIC)/libncc.o
TEST_MODULE_OBJFILE = test.o
TEST_MODULE_SRCFILE = test.c

FORCE_REBUILD_OBJFILES = $(TEST_MODULE_OBJFILE)

.PHONY: default all clean indent $(EXECUTABLES) \
$(FORCE_REBUILD_OBJFILES)

default: libncc

%.o: %.c
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -c -o $@ $<

indent:
	@echo "Indenting all files..."
	@./indent.sh "$(INDENT_OPTS)" "$(SPLINT_OPTS)" \
"$(PRG_OBJFILES) $(TEST_MODULE_OBJFILE)"
	@echo "Done."

clean:
	@echo "Removing object files..."
	@rm -fv {*,*/*}.{o,out,a}
	@echo "Object files removed."

# Always clean the test module before compiling the rest.
$(TEST_MODULE_OBJFILE): $(TEST_MODULE_SRCFILE)
	@rm -rf $(TEST_MODULE_OBJFILE)
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -c -o $@ $<

target list_base: override DEFFLAG = -DLIST_BASE_C \
-DSIMPLE_TEST -DTEST_ITERATIONS=$(TEST_ITERATIONS)
list_base: $(TEST_MODULE_OBJFILE) $(PRIVATE)/utils.o \
$(PRIVATE)/list_base.o
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target list_extended: override DEFFLAG = -DLIST_EXTENDED_C \
-D$(TEST_TYPE) -DTEST_ITERATIONS=$(TEST_ITERATIONS)
list_extended: $(TEST_MODULE_OBJFILE) $(PRIVATE)/utils.o \
$(PRIVATE)/list_base.o $(PRIVATE)/list_extended.o
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target stack: override DEFFLAG = -DSTACK_C -D$(TEST_TYPE) \
-DTEST_ITERATIONS=$(TEST_ITERATIONS)
stack: $(TEST_MODULE_OBJFILE) $(PRIVATE)/utils.o \
$(PRIVATE)/list_base.o $(PRIVATE)/list_extended.o $(ADT)/stack.o
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target queue: override DEFFLAG = -DQUEUE_C -D$(TEST_TYPE) \
-DTEST_ITERATIONS=$(TEST_ITERATIONS)
queue: $(TEST_MODULE_OBJFILE) $(PRIVATE)/utils.o \
$(PRIVATE)/list_base.o $(PRIVATE)/list_extended.o \
$(PRIVATE)/list_extras.o $(ADT)/queue.o
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target list: override DEFFLAG = -DLIST_C -D$(TEST_TYPE) \
-DTEST_ITERATIONS=$(TEST_ITERATIONS)
list: $(TEST_MODULE_OBJFILE) $(PRIVATE)/utils.o \
$(PRIVATE)/list_base.o $(PRIVATE)/list_extended.o \
$(PRIVATE)/list_extras.o $(ADT)/queue.o $(ADT)/stack.o \
$(ADT)/list.o
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

target api: override DEFFLAG = -DAPI -D$(TEST_TYPE) \
-DTEST_ITERATIONS=$(TEST_ITERATIONS)
api: $(TEST_MODULE_OBJFILE) $(PRG_OBJFILES)
	@$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out $^
	@echo "$(CC) $(INCLUDEDIR) $(CFLAGS) $(CSTANDARD) \
$(DEFFLAG) $(LIBS) -o $@.out"
	@./validate.sh $@.out

# Always replace the new archive.
target libncc: override DEFFLAG = -DelementObject=$(TYPE)
libncc: $(PRG_OBJFILES)
	@ar -cvr $@.a $(PRG_OBJFILES)

