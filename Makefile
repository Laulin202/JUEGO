all: compile game link

compile:
	g++ -I src/include -c main.cpp game.cpp
game: game.cpp game.h
	g++ -I src/include -c game.cpp
link:
	g++ main.o game.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio -l sfml-network