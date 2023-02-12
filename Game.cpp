#include "Game.hpp"
#include "PlayScreen.hpp"
#include "TitleScreen.hpp"

#include <iostream>

void Game::start() {
	screens.registerScreen<PlayScreen>(Screen::Type::PLAY);
	screens.registerScreen<TitleScreen>(Screen::Type::TITLE);
	screens.pushScreen(Screen::Type::TITLE);
}

void Game::update(float dt) {
	screens.update(dt);
}

void Game::draw(sf::RenderWindow& window) {
	screens.draw(window);

	gui.draw();
}

void Game::stop() {
	screens.close();
}