#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Game.hpp"


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Multiplayer Zelda");

    // init imgui-SFML
    ImGui::SFML::Init(window);

    // start the game
    Game::Start();
    
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
        Game::Update(elapsed.asSeconds());

        // draw section
        window.clear();
        Game::Draw(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    // cleanup
    window.close();
    // call this after window.close
    ImGui::SFML::Shutdown();

    return 0;
}