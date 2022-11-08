#include "ScreenStack.hpp"
#include <algorithm>

/*
	creates a new screen
	returns a shared pointer to that screen
*/
Screen::Pointer ScreenStack::createScreen(Screen::Type type) {
	return screenFactories[type]();
}

/*
	starts a new screen
*/
void ScreenStack::pushScreen(Screen::Type type) {
	activeScreens.push_back(createScreen(type));
}

/*
	closes the given screen
*/
void ScreenStack::popScreen() {
	activeScreens.pop_back();
}

/*
	closes top-most screen and opens a new one
*/
void ScreenStack::switchToScreen(Screen::Type type) {
	popScreen();
	pushScreen(type);
}

/*
	update all active screens
*/
void ScreenStack::update(float dt) {
	for(Screen::Pointer s : activeScreens)
		(*s).update(dt);
}

/*
	draw all active screens
*/
void ScreenStack::draw(sf::RenderWindow& window) {
	for(Screen::Pointer s : activeScreens)
		(*s).draw(window);
}

/*
	close all screens
*/
void ScreenStack::close() {
	for(Screen::Pointer s : activeScreens)
		(*s).close();

	activeScreens.clear();
}