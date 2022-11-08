#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "AssetManager.hpp"
#include "ScreenStack.hpp"
#include "TitleScreen.hpp"

ScreenStack screens;

void Game::Start() {
	screens.registerScreen<TitleScreen>(Screen::Type::MENU);
	screens.pushScreen(Screen::Type::MENU);
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