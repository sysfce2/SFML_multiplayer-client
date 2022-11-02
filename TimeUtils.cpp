#include "TimeUtils.hpp"
#include <SFML/System/Clock.hpp>

sf::Clock deltaClock;
sf::Time deltaTime;

/*
	set current delta time to zero
*/
void TimeUtils::ResetDelta() {
	deltaTime = deltaClock.restart();
}

/*
	get time elapsed since last frame (in seconds)
*/
float TimeUtils::GetDelta() {
	return deltaTime.asSeconds();
}