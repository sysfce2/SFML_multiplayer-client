#pragma once

#include <string>
#include <SFML/Network.hpp>
#include "IWidget.hpp"

class NetworkWidget : public IWidget {
private:
	sf::TcpSocket& socket;
	sf::TcpSocket::Status status;

	int portInput = 39964;
	std::string ipInput = "localhost";
public:
	NetworkWidget(sf::TcpSocket& socket)
		: socket(socket), status(sf::Socket::Disconnected) {};

	void draw() override;
};