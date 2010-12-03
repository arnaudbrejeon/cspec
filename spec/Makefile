CC=gcc

INCLUDE=../inc
LIB = ../src/libcspec.a

CFLAGS=-g -Wall -I$(INCLUDE)

SRC = spec_runner.c cspec_output_junit_xml_spec.c array_spec.c
OBJ = $(SRC:.c=.o)
TESTER = spec

all: $(TESTER)

$(TESTER): $(OBJ) $(INCLUDE)/*.h $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

clean:
	rm $(TESTER) $(OBJ)
