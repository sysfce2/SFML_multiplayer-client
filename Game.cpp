#include "Game.hpp"
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "ScreenStack.hpp"
#include "ResourceHolder.hpp"
#include "TitleScreen.hpp"
#include "PlayScreen.hpp"

sf::TcpSocket socket;
Screen::Context context;
ScreenStack screens(context);

void Game::Start() {
	// networking
	if(socket.connect("localhost", 39964) != sf::Socket::Done) {
		std::cout << "Something went wrong" << std::endl;
		return;
	}
	
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