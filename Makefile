CC = zig cc
LDFLAGS = -lraylib 

all:run

build:
	$(CC) src/main.c $(LDFLAGS) 

run:build
	./a.out


