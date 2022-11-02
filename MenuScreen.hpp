#pragma once
#include "Screen.hpp"

class MenuScreen : public Screen {
private:
	MenuScreen() {};
public:
	void Open()							override;
	void Update(float dt)				override;
	void Draw(sf::RenderWindow* window) override;
	void Close()						override;

	static MenuScreen& GetInstance() {
		static MenuScreen instance;
		return instance;
	}
};