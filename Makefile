
adventure: adventure.o player.o backpack.o item.o location.o locations.o npc.o
	clang++ --std=c++11  adventure.o Player.o Item.o Backpack.o Location.o Locations.o Npc.o -o adventure
adventure.o: adventure.cpp
	clang++ --std=c++11 -c adventure.cpp
player.o: Player.cpp Player.h
	clang++ --std=c++11 -c Player.cpp
backpack.o: Backpack.cpp Backpack.h
	clang++ --std=c++11 -c Backpack.cpp
item.o: Item.cpp Item.h
	clang++ --std=c++11 -c Item.cpp
location.o: Location.cpp Location.h
	clang++ --std=c++11 -c Location.cpp
locations.o: Locations.cpp Locations.h
	clang++ --std=c++11 -c Locations.cpp
npc.o: Npc.cpp Npc.h
	clang++ -c Npc.cpp
clean:
	rm *.o adventure