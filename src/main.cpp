#include <SFML/Graphics.hpp>
#include <Sapper.h>

int main(int argc, char *argv[])
{
    Sapper sapper_game;
    sapper_game.print();





    while (main_window.isOpen()) {
        
        sf::Event event;
        while (main_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) main_window.close();

            main_window.display();
        }
    }
    return 0;
}