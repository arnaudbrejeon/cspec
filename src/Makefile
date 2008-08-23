# define some aliases

CC=gcc
AR=ar

INCLUDE=../inc

CFLAGS=-g -I$(INCLUDE)

#SRC = cspec_output_header.c cspec_output_verbose.c cspec_runner.c cspec_config.c cspec_output_unit.c cspec_private.c
OBJ = cspec_output_header.o cspec_output_verbose.o cspec_runner.o cspec_config.o cspec_output_unit.o cspec_private.o
LIB = cspec.a

all: $(LIB)

$(LIB): $(OBJ) $(INCLUDE)/*.h
	$(AR) cr $(LIB) $(OBJ)

clean:
	rm $(LIB) $(OBJ)