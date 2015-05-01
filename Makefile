CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp textures.cpp keyboard.cpp mouse.cpp
	g++ $(CFLAGS) -o computer computer.cpp textures.cpp keyboard.cpp mouse.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
