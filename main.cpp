#include <iostream>
#include "Game.h"

int main() {
	std::srand((unsigned)time(NULL));

	Game game;
	game.createWorld();
	game.update();

	game.render();
	while(game.getWindowIsOpen()) {
		while (game.getWindowIsOpen()) {
			game.update();
			game.render();
		}
	}

	return 0;

}