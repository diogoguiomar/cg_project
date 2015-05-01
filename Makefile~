CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp texturas.cpp teclado.cpp
	g++ $(CFLAGS) -o computer computer.cpp texturas.cpp teclado.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
