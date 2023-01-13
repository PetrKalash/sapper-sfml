#include "Sapper.h"

Sapper::Sapper()
{
    m_texture_tiles.loadFromFile("resources//img//tiles.jpg");
    m_sprite_tiles.setTexture(m_texture_tiles);

    // Заполняем каждую ячейку на игровом поле случайными числами
    for (size_t x{}; x < 10; ++x)
        for (size_t y{}; y < 10; ++y)
            m_fill_field.at(x).at(y) = std::mt19937(std::random_device {}())() % 6;
}

void Sapper::print()
{
    for (size_t i{}; i < 10; ++i) {
        for (size_t j{}; j < 10; ++j) {
            sprite_tiles.setTextureRect(sf::IntRect(320, 0, 32, 32));
            sprite_tiles.setPosition(10, 10);
            main_window.draw(sprite_tiles);
        }
    }
}