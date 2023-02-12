#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Game.hpp"


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Multiplayer Zelda");

    // init imgui-SFML
    ImGui::SFML::Init(window);

    // init game
    Game game;

    // start the game
    game.start();
    
    // start clock
    sf::Clock deltaClock;

    // game loop
    while (window.isOpen())
    {   
        // poll sfml events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // pass events to imgui-SFML
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // get delta time
        sf::Time elapsed = deltaClock.restart();

        // update section
        ImGui::SFML::Update(window, elapsed);
        game.update(elapsed.asSeconds());

        // draw section
        window.clear();
        game.draw(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    // cleanup
    window.close();
    // call this after window.close
    ImGui::SFML::Shutdown();

    return 0;
}