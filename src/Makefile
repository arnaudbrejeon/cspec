# define some aliases

CC=gcc
AR=ar

INCLUDE=../inc

CFLAGS=-g -Wall -I$(INCLUDE)

OBJ = cspec_output_header.o cspec_output_verbose.o cspec_output_xml.o cspec_runner.o cspec_config.o cspec_output_unit.o cspec_private.o cspec_output.o array.o cspec_output_junit_xml.o
LIB = libcspec.a

all: $(LIB)

$(LIB): $(OBJ) $(INCLUDE)/*.h
	$(AR) cr $(LIB) $(OBJ)

clean:
	rm -f $(LIB) $(OBJ)
