CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp textures.cpp keyboard.cpp
	g++ $(CFLAGS) -o computer computer.cpp textures.cpp keyboard.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
