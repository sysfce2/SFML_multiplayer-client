#include "TitleScreen.hpp"

TitleScreen::TitleScreen(ScreenStack& screenStack, Screen::Context& context)
	: Screen(screenStack, context) {

}

void TitleScreen::update(float dt) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		getScreenStack().switchToScreen(Screen::Type::PLAY);
}

void TitleScreen::draw(sf::RenderWindow& window) {

}

void TitleScreen::close() {

}