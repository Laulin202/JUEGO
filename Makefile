VIEW := view
CONTROLLER := controller
MODEL := model
debug := -ggdb3

all: link clean
link: SpriteA Teclado TileMap Tile Entity Item Potion Player Enemy Boton Spell Combate JuegoMain  Inventory PauseMenu
	g++ -o main SpriteA.o Teclado.o TileMap.o Tile.o Entity.o Player.o Enemy.o Button.o Spell.o Combat.o Item.o Potion.o Inventory.o PauseMenu.o juego.o main.o -L src/lib -l sfml-graphics -l sfml-window -l sfml-system 
Player:${MODEL}/Player.cpp ${MODEL}/Player.h
	g++ -I src/include -c ${debug} ${MODEL}/Player.cpp
Enemy:${MODEL}/Enemy.cpp ${MODEL}/Enemy.h
	g++ -I src/include -c ${debug} ${MODEL}/Enemy.cpp
Entity:${MODEL}/Entity.cpp ${MODEL}/Entity.h
	g++ -I src/include -c ${debug} ${MODEL}/Entity.cpp
SpriteA:${MODEL}/SpriteA.cpp ${MODEL}/SpriteA.h
	g++ -I src/include -c ${debug} ${MODEL}/SpriteA.cpp
Teclado:${MODEL}/Teclado.cpp ${MODEL}/Teclado.h
	g++ -I src/include -c ${debug} ${MODEL}/Teclado.cpp
TileMap:${MODEL}/TileMap.cpp ${MODEL}/TileMap.h
	g++ -I src/include -c ${debug} ${MODEL}/TileMap.cpp
Tile:${MODEL}/Tile.cpp ${MODEL}/Tile.h
	g++ -I src/include -c ${debug} ${MODEL}/Tile.cpp
Boton:${MODEL}/Button.cpp ${MODEL}/Button.h
	g++ -I src/include -c ${debug} ${MODEL}/Button.cpp 
Combate:${MODEL}/Combat.cpp ${MODEL}/Combat.h
	g++ -I src/include -c ${debug} ${MODEL}/Combat.cpp
Item:${MODEL}/Item.cpp ${MODEL}/Item.h
	g++ -I src/include -c ${debug} ${MODEL}/Item.cpp
Potion:${MODEL}/Potion.cpp ${MODEL}/Potion.h
	g++ -I src/include -c ${debug} ${MODEL}/Potion.cpp
Inventory:${MODEL}/Inventory.cpp ${MODEL}/Inventory.h
	g++ -I src/include -c ${debug} ${MODEL}/Inventory.cpp
PauseMenu:${MODEL}/PauseMenu.cpp ${MODEL}/PauseMenu.h
	g++ -I src/include -c ${debug} ${MODEL}/PauseMenu.cpp
Spell:${MODEL}/Spell.cpp ${MODEL}/Spell.h
	g++ -I src/include -c ${debug} ${MODEL}/Spell.cpp
JuegoMain: juego.cpp main.cpp juego.h
	g++ -I src/include -c ${debug} juego.cpp main.cpp	
clean: #comando para borrar los .o
	@echo "Limpio los archivos intermedios de las carpetas ..."+ ${MODEL} + ${VIEW}
	rm -f *.o

