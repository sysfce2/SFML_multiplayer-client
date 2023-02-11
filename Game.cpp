#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "ScreenStack.hpp"
#include "TitleScreen.hpp"
#include "PlayScreen.hpp"

Screen::Context context;
ScreenStack screens(context);

void Game::Start() {
	screens.registerScreen<PlayScreen>(Screen::Type::PLAY);
	screens.registerScreen<TitleScreen>(Screen::Type::TITLE);
	screens.pushScreen(Screen::Type::TITLE);
}

void Game::Update(float dt) {
	screens.update(dt);
}

void Game::Draw(sf::RenderWindow& window) {
	screens.draw(window);
}

void Game::Stop() {
	screens.close();
}