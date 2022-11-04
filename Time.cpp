#include "Time.hpp"
#include <SFML/System/Clock.hpp>

sf::Clock deltaClock;
sf::Time deltaTime;

/*
	set current delta time to zero
*/
void Time::ResetDelta() {
	deltaTime = deltaClock.restart();
}

/*
	get time elapsed since last frame (in seconds)
*/
float Time::GetDelta() {
	return deltaTime.asSeconds();
}