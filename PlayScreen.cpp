#include "PlayScreen.hpp"
#include <iostream>
#include "Time.hpp"
#include "Resources.hpp"
#include "Components.hpp"
#include "ResourceHolder.hpp"

PlayScreen::PlayScreen(ScreenStack& screenStack, Screen::Context& context)
	: Screen(screenStack, context) {

	auto& textures = getContext().textures;
	auto& entities = getContext().entities;

	textures.load(Textures::Player, "player.png");

	const auto entity = entities.create();

	entities.emplace<CPosition>(entity);
	entities.emplace<CVelocity>(entity);
	entities.emplace<CController>(entity);
	entities.emplace<CDraw>(entity, textures.get(Textures::Player));
}

void PlayScreen::update(float dt) {
	auto& entities = getContext().entities;

	//
	auto controllers = entities.view<CController>();
	
	controllers.each([](auto& controller) {
		controller.up		= sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		controller.left		= sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		controller.down		= sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		controller.right	= sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	});
	//

	//
	auto movables = entities.view<CPosition, CVelocity>();

	movables.each([&entities](const auto entity, auto& position, auto& velocity) {
		velocity.verticalAxis = 0;
		velocity.horizontalAxis = 0;

		if(entities.any_of<CController>(entity)) {
			auto& controller = entities.get<CController>(entity);

			if(controller.up)		velocity.verticalAxis	= -1;
			if(controller.left)		velocity.horizontalAxis = -1;
			if(controller.down)		velocity.verticalAxis	= +1;
			if(controller.right)	velocity.horizontalAxis = +1;

			if(velocity.horizontalAxis != 0 && velocity.verticalAxis != 0) {
				velocity.verticalAxis	/= std::sqrt(2.f);
				velocity.horizontalAxis /= std::sqrt(2.f);
			}
		}

		position.y += velocity.speed * velocity.verticalAxis   * Time::GetDelta();
		position.x += velocity.speed * velocity.horizontalAxis * Time::GetDelta();
	});
	//
}

void PlayScreen::draw(sf::RenderWindow& window) {
	auto& entities = getContext().entities;

	auto drawables = entities.view<CDraw>();

	drawables.each([&entities, &window](const auto entity, auto& draw) {

		if(entities.any_of<CPosition>(entity)) {
			auto& position = entities.get<CPosition>(entity);
			auto& sprite = draw.sprite;

			sprite.setPosition({position.x, position.y});
		}


		window.draw(draw.sprite);
	});
}

void PlayScreen::close() {

}