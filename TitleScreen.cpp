#include "TitleScreen.hpp"
#include <iostream>

void TitleScreen::update(float dt) {
	std::cout << "Hello, update" << std::endl;
}

void TitleScreen::draw(sf::RenderWindow& window) {
	std::cout << "Hello, draw" << std::endl;
}

void TitleScreen::close() {
	std::cout << "Hello, close" << std::endl;
}