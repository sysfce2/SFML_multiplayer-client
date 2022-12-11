#include "PlayScreen.hpp"
#include <iostream>
#include "Resources.hpp"
#include "Components.hpp"
#include "ResourceHolder.hpp"

sf::Sprite player;

PlayScreen::PlayScreen(ScreenStack& screenStack, Screen::Context& context)
	: Screen(screenStack, context) {

	auto& textures = getContext().textures;

	textures.load(Textures::Player, "player.png");
	player.setTexture(textures.get(Textures::Player));
}

void PlayScreen::update(float dt) {
	auto& entities = getContext().entities;

	//
	auto controllables = entities.view<CController>();
	
	controllables.each([](auto& controller) {
		controller.up		= sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		controller.left		= sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		controller.down		= sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		controller.right	= sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	});
	//

	//
	
	//

	//
	auto movables = entities.view<CPosition, CVelocity>();

	movables.each([&entities](const auto entity, auto& position, auto& velocity) {
		position.x += velocity.dx;
		position.y += velocity.dy;

		if(entities.any_of<CController>(entity)) {
			auto& controller = entities.get<CController>(entity);
			if(controller.up)		velocity.dy -= 1;
			if(controller.left)		velocity.dx -= 1;
			if(controller.down)		velocity.dy += 1;
			if(controller.right)	velocity.dx += 1;
		}

		if(!velocity.frictionless) {
			velocity.dx += (velocity.dx > 0 ? -0.5 : 0.5);
			velocity.dy += (velocity.dy > 0 ? -0.5 : 0.5);
		}
	});
	//
}

void PlayScreen::draw(sf::RenderWindow& window) {
	auto& entities = getContext().entities;

	auto drawables = entities.view<const CDraw>();
	drawables.each([&window](const auto& draw) {
		window.draw(draw.sprite);
	});
}

void PlayScreen::close() {

}