VIEW := view
CONTROLLER := controller
MODEL := model
debug := -ggdb3

all: Main link 
link:Entity Player Juego  
	g++ -o main Entity.o Player.o juego.o main.o -L src/lib -l sfml-graphics -l sfml-window -l sfml-system 
Player:${MODEL}/Player.cpp ${MODEL}/Player.h
	g++ -I src/include -c ${debug} ${MODEL}/Player.cpp
Entity:${MODEL}/Entity.cpp ${MODEL}/Entity.h
	g++ -I src/include -c ${debug} ${MODEL}/Entity.cpp
Juego: juego.cpp juego.h
	g++ -I src/include -c ${debug} juego.cpp
Main: main.cpp juego.h
	g++ -I src/include -c ${debug} main.cpp	
 

