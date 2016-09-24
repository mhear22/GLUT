CC=clang
SRC=Engine/Source/
OBJ=$(SRC)*.cpp
CFLG= -std=c++11
LIBS=
UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
LIBS=-framework OpenGL -I/usr/include -lglfw -lglfw3
endif

ifeq ($(UNAME),Windows)
LIBS= -I /usr/include -lXmu -lglut -lGL -lGLU -lm -lGLEW -lglfw3 -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl
endif


all: Main
	
Main:
	clear
	$(CC) $(OBJ) $(LIBS) $(CFLG)
	
clean:
	rm a.out
