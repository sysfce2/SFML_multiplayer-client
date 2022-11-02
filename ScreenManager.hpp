#pragma once
#include "Screen.hpp"

namespace ScreenManager {
	/*
		starts a new screen without closing the current one
	*/
	void StartScreen(Screen* screen);

	/*
		closes the current screen and starts a new one
	*/
	void ChangeScreen(Screen* screen);

	/*
		closes the current screen and starts a new one
		also applies a transiton effect
	*/
	void TransitionScreen(Screen* screen);

	/*
		get current open screen
	*/
	Screen* GetCurrent();
}