CFLAGS = -Wall
LDFLAGS = -lm

computador: computer.cpp
	g++ $(CFLAGS) -o computer computer.c -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
