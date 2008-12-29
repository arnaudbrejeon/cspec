# define some aliases

CC=gcc

INCLUDE=../inc

CFLAGS=-g -I$(INCLUDE)

LIB=../src/libcspec.a

#SRC = fabs_desc.c main.c
OBJ = fabs_desc.o main.o
EXE = sample

all: $(EXE)

$(EXE): $(OBJ) $(INCLUDE)/*.h $(LIB)
	$(CC) -o $(EXE) $(OBJ) $(LIB)

clean:
	rm $(EXE)* $(OBJ) *.xml