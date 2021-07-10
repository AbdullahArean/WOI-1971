#Write "make" int terminal to build the game from code
build:
	g++ -Wall ./src/*.cpp -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -o "WOI-1971"
#Write "make play" in terminal to play the game
play:
	./"WOI-1971"
#Write "make clean" in terminal to delete executable game
clean:
	rm "WOI-1971"
