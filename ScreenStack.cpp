#include "ScreenStack.hpp"

/*
	defines a pending change
	this is used to push or pop screens in the stack
	pushing and popping only happens after the update loop ends because we want to
	ensure that we only write to activeScreens when nobody is reading (thread-safing)
*/
ScreenStack::PendingChange::PendingChange(MemoryAction action, Screen::Type screenType)
	: action(action), screenType(screenType) {};

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
	pendingChanges.emplace_back(MemoryAction::PUSH, type);
}

/*
	closes the given screen
*/
void ScreenStack::popScreen() {
	pendingChanges.emplace_back(MemoryAction::POP);
}

/*
	closes top-most screen and opens a new one
	TODO: make this safer
*/
void ScreenStack::switchToScreen(Screen::Type type) {
	popScreen();
	pushScreen(type);
}

/*
	update the screen stack
	- update all screens (read the stack)
	- apply any pending changes (write to the stack while there are no readers)
	- clear pending changes
	these steps SHOULD make the ScreenStack thread-safe
*/
void ScreenStack::update(float dt) {
	// update screens
	for(Screen::Pointer& s : activeScreens)
		s->update(dt);

	// apply pending changes
	for(PendingChange change : pendingChanges)
		switch(change.action)
		{
			case MemoryAction::POP:
				activeScreens.pop_back();
				break;

			case MemoryAction::PUSH:
				activeScreens.push_back(createScreen(change.screenType));
				break;
		}

	// clear pending changes
	pendingChanges.clear();
}

/*
	draw all active screens
*/
void ScreenStack::draw(sf::RenderWindow& window) {
	for(Screen::Pointer& s : activeScreens)
		s->draw(window);
}

/*
	close all screens
*/
void ScreenStack::close() {
	for(Screen::Pointer& s : activeScreens)
		s->close();

	activeScreens.clear();
}