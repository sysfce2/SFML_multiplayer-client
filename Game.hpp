#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace Game {
	void Start();
	void Update(float dt);
	void Draw(sf::RenderWindow* window);
	void Stop();
}