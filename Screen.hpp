#pragma once
#include <SFML/Graphics.hpp>

// we have to forward declare ScreenStack class
// otherwise we'd have a recursive inclusion between these two
class ScreenStack;

class Screen {
public:
	typedef std::shared_ptr<Screen> Pointer;
	enum Type { MENU, PLAY };
protected:
	ScreenStack& screenStack;
public:
	virtual ~Screen() {};
	Screen(ScreenStack& screenStack) : screenStack(screenStack) {};

	virtual void update(float dt)				= 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void close()						= 0;
};