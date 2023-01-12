#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Sapper
{
private:
    std::array<std::array<int32_t, 10>, 10> m_fill_field;     // игровое поле

public:
    Sapper()
    {
        // Заполняем каждую ячейку на игровом поле случайными числами
        for (size_t x{}; x < 10; ++x)
            for (size_t y{}; y < 10; ++y)
                m_fill_field.at(x).at(y) = std::mt19937(std::random_device {}())() % 9;
    }
};

int main(int argc, char *argv[])
{
    sf::RenderWindow main_window(sf::VideoMode(400, 400), "Sapper");

    sf::Texture texture_tiles;
    texture_tiles.loadFromFile("resources//img//tiles.jpg");

    sf::Sprite sprite_tiles(texture_tiles);

    Sapper sapper_game;

    while (main_window.isOpen()) {
        
        sf::Event event;
        while (main_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) main_window.close();
        }

        for (size_t i{}; i < 10; ++i) {
            for (size_t j{}; j < 10; ++j) {
                sprite_tiles.setTextureRect(sf::IntRect(320, 0, 32, 32));
                sprite_tiles.setPosition(10, 10);
                main_window.draw(sprite_tiles);
            }
        }

        main_window.display();
    }
    return 0;
}