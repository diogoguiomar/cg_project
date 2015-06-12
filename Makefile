CFLAGS = -Wall
LDFLAGS = -lm

main: main.cpp textures.cpp keyboard.cpp mouse.cpp screen.cpp tower.cpp menu.cpp shadows.cpp table.cpp wires.cpp
	g++ $(CFLAGS) -o main main.cpp textures.cpp keyboard.cpp mouse.cpp screen.cpp tower.cpp menu.cpp shadows.cpp wires.cpp table.cpp -lGL -lGLU -lglut $(LDFLAGS)

clean:
	rm main
