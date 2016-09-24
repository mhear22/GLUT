CC=clang
SRC=Engine/Source/
OBJ=$(SRC)*.cpp
CFLG= -Wall -std=c++11
LIBS=
INCL=
FRMWK=
UNAME := $(shell uname)
EXE=a.out

ifeq ($(UNAME),Darwin)
LIBS=-lGL -lGLEW -lglfw3
INCL=-L/usr/local/lib -I/usr/lib
FRMWK=-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

#-lglfw3 -lrt -lXrandr -lXinerama -lXi -lXcursor -lGL -lm -ldl -lXrender -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm -lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp
endif

ifeq ($(UNAME),Windows)
LIBS= -I /usr/include -lXmu -lglut -lGL -lGLU -lm -lGLEW -lglfw3 -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl
endif


all: Main
	
Main:
	$(CC) $(OBJ) $(FRMWK) $(INCL) $(LIBS) $(CFLG) -o $(EXE)
	
clean:
	rm $(EXE)
