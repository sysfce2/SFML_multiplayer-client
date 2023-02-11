#include "TitleScreen.hpp"

#include "imgui.h"

TitleScreen::TitleScreen(ScreenStack& screenStack, Screen::Context& context)
	: Screen(screenStack, context) {

}

void TitleScreen::update(float dt) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		getScreenStack().switchToScreen(Screen::Type::PLAY);
}

void TitleScreen::draw(sf::RenderWindow& window) {
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoCollapse);

	

	if(ImGui::Button("Play")) {
		
	}

	ImGui::End();
}

void TitleScreen::close() {

}