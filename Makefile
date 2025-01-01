CC = zig cc
LDFLAGS = -lraylib 
SRC = ./src

all:run

build:
	$(CC) $(SRC)/main.c $(LDFLAGS) 

run:build
	./a.out


