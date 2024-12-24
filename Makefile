CC = zig cc
RAYLIB ?= ./external/raylib-5.5/src/
RAYGUI ?= ./external/raygui-4.0/src/
GUIPATH = -I $(RAYGUI) -L $(RAYGUI)  
RAYPATH = -I $(RAYLIB) -L $(RAYLIB)
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:run

build:
	$(CC) src/main.c  $(LDFLAGS) $(GUIPATH) $(RAYPATH)

run:build
	./a.out


