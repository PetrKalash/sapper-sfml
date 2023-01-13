#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Sapper
{
protected:
    sf::Texture m_texture_tiles;                            // обща€ текстура
    sf::Sprite m_sprite_tiles;                              // спрайты игровых €чеек

private:
    std::array<std::array<int32_t, 10>, 10> m_fill_field;   // сгенерированное поле
    std::array<std::array<int32_t, 10>, 10> m_logic_field;  // игрова€ логика пол€

public:
    Sapper();

    // ƒобавление спрайта €чейки
    void add_sprite_tiles();
    // ¬озвращеник спрайта €чейки
    sf::Sprite get_sprite_tiles() const;
};