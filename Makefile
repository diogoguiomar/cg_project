CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp
	g++ $(CFLAGS) computer.cpp -o computer -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
