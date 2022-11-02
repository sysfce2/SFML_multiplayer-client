#include "ScreenManager.hpp"
#include <stack>

std::stack<Screen*> activeScreens;
Screen* currentScreen;

/*
	starts a new screen without closing the current one
*/
void ScreenManager::StartScreen(Screen* screen) {
	currentScreen = screen;
	currentScreen->Open();
}

/*
	closes the current screen and starts a new one
*/
void ScreenManager::ChangeScreen(Screen* screen) {
	screen->Close();
	StartScreen(screen);
}

/*
	closes the current screen and starts a new one
	also applies a transiton effect
*/
void ScreenManager::TransitionScreen(Screen* screen) {
	// IMPLEMENTATION REQUIRED
}

Screen* ScreenManager::GetCurrent() {
	return currentScreen;
}