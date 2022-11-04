#pragma once
#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>
#include "Screen.hpp"

class ScreenStack {
private:
	std::vector<Screen::Pointer> activeScreens;
	std::unordered_map<Screen::Type, std::function<Screen::Pointer()>> screenFactories;
private:
	/*
		creates a new screen
		returns a shared pointer to that screen
	*/
	Screen::Pointer createScreen(Screen::Type type);
public:
	/*
		links a Screen::Type to a Screen class
		T = the class we want to link to that type
	*/
	template<class T>
	void registerScreen(Screen::Type type);

	/*
		starts a new screen
	*/
	void pushScreen(Screen::Type type);

	/*
		closes the given screen
	*/
	void popScreen();

	/*
		closes top-most screen and opens a new one
	*/
	void switchToScreen(Screen::Type type);

	/*
		update all active screens
	*/
	void update(float dt);

	/*
		draw all active screens
	*/
	void draw(sf::RenderWindow* window);
};