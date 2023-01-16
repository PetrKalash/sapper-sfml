#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Sapper
{
protected:
    sf::Texture m_texture_tiles;                                // обща€ текстура €чеек
    std::array<sf::Sprite, 12> m_sprite_tiles;                  // спрайты игровых €чеек

private:
    std::array<std::array<int32_t, 20>, 20> m_logic_field;        // игрова€ логика пол€
    std::array<std::array<int32_t, 20>, 20> m_fill_field;         // сгенерированное поле

public:
    Sapper();

    // «амена €чейки новым переданным значением спрайта после клика мыши
    void replace_fill_sprite(int32_t x_mouse, int32_t y_mouse, int32_t value);

    // ¬озвращение числа внешней €чейки
    std::array<std::array<int32_t, 20>, 20> get_fill_field() const;
    // ¬озвращение числа внутренней €чейки
    std::array<std::array<int32_t, 20>, 20> get_logic_field() const;
    // ¬озвращение спрайта €чейки
    std::array<sf::Sprite, 12> get_sprite_tiles() const;
};