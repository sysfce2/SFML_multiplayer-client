#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenStack.hpp"

class Screen {
public:
	typedef std::shared_ptr<Screen> Pointer;
	enum Type { MENU, PLAY };
protected:
	ScreenStack* screenStack;
protected:
	Screen(ScreenStack* screenStack) : screenStack(screenStack) {};
public:
	virtual ~Screen() {};

	virtual void open()							= 0;
	virtual void update(float dt)				= 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void close()						= 0;
};