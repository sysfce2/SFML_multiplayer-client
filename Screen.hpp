#pragma once
#include <SFML/Graphics.hpp>

class Screen {
public:
	virtual void Open()							= 0;
	virtual void Update(float dt)				= 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void Close()						= 0;
};