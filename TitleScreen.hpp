#pragma once
#include "Screen.hpp"

class TitleScreen : Screen {
	void open()							override;
	void update(float dt)				override;
	void draw(sf::RenderWindow* window) override;
	void close()						override;
};