build:
	g++ -Wall ./src/*.cpp -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -o "WOI-1971"
play:
	./"WOI-1971"
clean:
	rm "WOI-1971"
