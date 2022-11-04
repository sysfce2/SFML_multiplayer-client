#pragma once
#include <SFML/Graphics/Texture.hpp>

struct CPosition {
	float x;
	float y;
};

struct CVelocity {
	float dx;
	float dy;
};

struct CGraphics {
	sf::Texture texture;
};