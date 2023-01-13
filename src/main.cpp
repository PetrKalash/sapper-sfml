#include <SFML/Graphics.hpp>
#include <Sapper.h>

int main(int argc, char *argv[])
{
    sf::RenderWindow main_window(sf::VideoMode(400, 400), "Sapper");

    Sapper sapper_game;
    sapper_game.print();





    while (main_window.isOpen()) {
        
        sf::Event event;
        while (main_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) main_window.close();

            //if (event.type == sf::Event::MouseButtonPressed) 


            main_window.display();
        }
    }
    return 0;
}