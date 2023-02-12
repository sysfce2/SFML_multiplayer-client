#pragma once
#include <list>
#include <entt.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.hpp"
#include "ResourceHolder.hpp"

// remember to include ScreenStack.hpp in the header files of other screens!
class ScreenStack;

class Screen {
public:
	/*
		define a screen::pointer type
	*/
	typedef std::unique_ptr<Screen> Pointer;

	/*
		declare every possible screen type
	*/
	enum Type { NONE, TITLE, PLAY };

	/*
		declare a screen context
		a context is an object which holds every resource that shouldn't
		always be re-loaded when a screen changes
		it should be passed to a new screen when it's loaded
	*/
	struct Context {
		entt::registry entities;
		ResourceHolder<Textures::ID, sf::Texture> textures;
	};
private:
	ScreenStack& screenStack;
	Screen::Context& context;
protected:
	ScreenStack& getScreenStack() { return screenStack; }
	Screen::Context& getContext() { return context;		}
public:
	virtual ~Screen() {};
	Screen(ScreenStack& screenStack, Screen::Context& context)
		: screenStack(screenStack), context(context) {};

	virtual void update(float dt)				= 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void close()						= 0;
};