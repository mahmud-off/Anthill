#include <iostream>
#include "Game.h"

int main() {
	std::srand((unsigned)time(NULL));

	Game game;
	if (game.getWindowIsOpen()) {

		
		while (game.getWindowIsOpen()) {
			game.update();
			game.render();
		}
	}

	return 0;

}