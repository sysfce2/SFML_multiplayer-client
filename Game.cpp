#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "AssetManager.hpp"
#include "ScreenManager.hpp"
#include <entt.hpp>
#include "MenuScreen.hpp"

void Game::Start() {
	ScreenManager::StartScreen(&MenuScreen::GetInstance());
}

void Game::Update(float dt) {

}

void Game::Draw(sf::RenderWindow* window) {

}

void Game::Stop() {

}