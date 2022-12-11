#pragma once
#include <SFML/Graphics/Sprite.hpp>

struct CPosition {
	float x;
	float y;
};

struct CVelocity {
	float dx;
	float dy;
	bool frictionless = false;
};

struct CDraw {
	sf::Sprite sprite;
};

struct CController {
	bool up;
	bool left;
	bool down;
	bool right;
};