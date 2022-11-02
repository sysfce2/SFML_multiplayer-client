#pragma once
#include <SFML/Graphics/Texture.hpp>

struct position {
	float x;
	float y;
};

struct velocity {
	float dx;
	float dy;
};

struct graphics {
	sf::Texture texture;
};