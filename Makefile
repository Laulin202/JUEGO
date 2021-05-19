VIEW := view
CONTROLLER := controller
MODEL := model
debug := -ggdb3

all: Main link 
link: SpriteA Teclado Entity Player Juego   
	g++ -o main SpriteA.o Teclado.o Entity.o Player.o juego.o main.o -L src/lib -l sfml-graphics -l sfml-window -l sfml-system 
Player:${MODEL}/Player.cpp ${MODEL}/Player.h
	g++ -I src/include -c ${debug} ${MODEL}/Player.cpp
Entity:${MODEL}/Entity.cpp ${MODEL}/Entity.h
	g++ -I src/include -c ${debug} ${MODEL}/Entity.cpp
SpriteA:${MODEL}/SpriteA.cpp ${MODEL}/SpriteA.h
	g++ -I src/include -c ${debug} ${MODEL}/SpriteA.cpp
Teclado:${MODEL}/Teclado.cpp ${MODEL}/Teclado.h
	g++ -I src/include -c ${debug} ${MODEL}/Teclado.cpp
Juego: juego.cpp juego.h
	g++ -I src/include -c ${debug} juego.cpp
Main: main.cpp juego.h
	g++ -I src/include -c ${debug} main.cpp	
 

