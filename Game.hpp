#pragma once
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Screen.hpp"
#include "ScreenStack.hpp"
#include "UIRenderer.hpp"

class Game {
private:
	sf::TcpSocket socket;
	sf::TcpSocket::Status socketStatus;

	ScreenStack screens;
	Screen::Context context;

	UIRenderer gui;
public:
	Game()
		: socketStatus(sf::Socket::Disconnected), screens(context) {}

	void start();
	void update(float dt);
	void draw(sf::RenderWindow& window);
	void stop();
};