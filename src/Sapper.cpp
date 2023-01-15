#include "Sapper.h"

Sapper::Sapper() : m_logic_field{}
{
    // «агружаем изображение игровых €чеек
    m_texture_tiles.loadFromFile("resources//img//tiles.jpg");

    // ¬ырезаем отдельно каждую €чейку у текстуры
    for (int32_t s{}; s < m_sprite_tiles.size(); ++s) {
        m_sprite_tiles.at(s).setTexture(m_texture_tiles);
        m_sprite_tiles.at(s).setTextureRect(sf::IntRect(s * 32, 0, 32, 32));
    }

    // ѕеребираем все €чейки на игровом поле
    for (int32_t x{}; x < m_fill_field.size(); ++x) {
        for (int32_t y{}; y < m_fill_field.size(); ++y) {
            // «аполн€ем каждую €чейку случайными числами (внутренн€€ часть). 0 - это мины, 9 - спрайт мин
            if (std::mt19937(std::random_device {}())() % 6 == 0) m_logic_field.at(x).at(y) = 9;
            // ” внешней части игрового пол€ (внешн€€ часть) все €чейки закрытые
            m_fill_field.at(x).at(y) = 10;
        }
    }

    // ƒл€ каждой клетки присваиваем кол-во мин р€дом с ней (квадрат 3x3)
    for (int32_t x{}; x < m_fill_field.size(); ++x) {
        for (int32_t y{}; y < m_fill_field.size(); ++y) {

            // ≈сли у €чейки есть мина, то ее не провер€ем и переходим к следующей
            if (m_logic_field.at(x).at(y) == 9) continue;

            // ѕровер€ем вокруг €чейки без мины квадратную область 3x3 на наличие мин
            for (int32_t i{x - 1}; i <= x + 1; ++i)
                for (int32_t j{y - 1}; j <= y + 1; ++j)
                    // ≈сли €чейка вокруг квадратной области текущей €чейки не выходит за границы пол€ и имеет мину, прибавл€ем +1
                    if (i >= 0 && j >= 0 && i < m_logic_field.size() && j < m_logic_field.size() && m_logic_field.at(i).at(j) == 9)
                        m_logic_field.at(x).at(y)++;
        }
    }
}

void Sapper::replace_fill_sprite(int32_t x_mouse, int32_t y_mouse, int32_t value)
{
    for (int32_t x{}; x < m_fill_field.size(); ++x)
        for (int32_t y{}; y < m_fill_field.size(); ++y)
            if (x_mouse == x && y_mouse == y) m_fill_field.at(x).at(y) = value;
}

std::array<std::array<int32_t, 10>, 10> Sapper::get_fill_field() const
{
    return m_fill_field;
}

std::array<std::array<int32_t, 10>, 10> Sapper::get_logic_field() const
{
    return m_logic_field;
}

std::array<sf::Sprite, 12> Sapper::get_sprite_tiles() const
{
    return m_sprite_tiles;
}
