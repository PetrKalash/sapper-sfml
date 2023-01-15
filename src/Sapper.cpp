#include "Sapper.h"

Sapper::Sapper()
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
            // «аполн€ем каждую €чейку случайными числами (внутренн€€ часть). 0 - это мины
            m_logic_field.at(x).at(y) = std::mt19937(std::random_device{}())() % 12;
            // ” внешней части все €чейки закрытые
            m_fill_field.at(x).at(y) = 10;
        }
    }

    // ƒл€ каждой клетки присваиваем кол-во мин р€дом с ней (квадрат 3x3)
    for (int32_t x {}; x < m_fill_field.size(); ++x) {
        for (int32_t y {}; y < m_fill_field.size(); ++y) {

            int32_t count_mine {};          // кол-во мин р€дом с клеткой

            // ≈сли у €чейки есть мина, то ее не провер€ем и переходим к следующей
            if (!m_logic_field.at(x).at(y)) continue;

            // ѕровер€ем вокруг €чейки без мин квадратную область 3x3 на наличие мин
            if (m_logic_field.at(x).at(y))

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
