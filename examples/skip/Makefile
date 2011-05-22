# define some aliases

CC=gcc

INCLUDE=../../inc

CFLAGS=-g -I$(INCLUDE)

LIB=../../src/libcspec.a

OBJ = skiplist_spec.o skip_list.o  main.o
EXE = sample_skip

all: $(EXE)

$(EXE): $(OBJ) $(INCLUDE)/*.h $(LIB)
	$(CC) -o $(EXE) $(OBJ) $(LIB)

clean:
	rm $(EXE) $(OBJ)
