#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Time.hpp"

int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Multiplayer Zelda");

    // event: game started
    Game::Start();
    
    // game loop
    while (window.isOpen())
    {   
        // set current dt to 0 because a new frame has started
        Time::ResetDelta();

        // poll sfml events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // get elapsed time since the start of this frame
        float dt = Time::GetDelta();
        // event: update
        Game::Update(dt);

        // event: draw
        window.clear();
        Game::Draw(window);
        window.display();
    }

    return 0;
}