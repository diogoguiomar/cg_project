CFLAGS = -Wall
LDFLAGS = -lm

computer: computer.cpp textures.cpp keyboard.cpp mouse.cpp screen.cpp tower.cpp menu.cpp
	g++ $(CFLAGS) -o computer computer.cpp textures.cpp keyboard.cpp mouse.cpp screen.cpp tower.cpp menu.cpp shadows.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm computer
