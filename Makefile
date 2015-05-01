CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp textures.cpp keyboard.cpp mouse.cpp menu.cpp
	g++ $(CFLAGS) -o computer computer.cpp textures.cpp keyboard.cpp mouse.cpp menu.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
