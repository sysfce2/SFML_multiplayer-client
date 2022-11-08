#pragma once
#include "Screen.hpp"

class TitleScreen : public Screen {
public:
	TitleScreen(ScreenStack& screenStack) : Screen(screenStack) {};

	void update(float dt)				override;
	void draw(sf::RenderWindow& window) override;
	void close()						override;
};