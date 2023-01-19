#include "sapper.h"

Sapper::Sapper() : m_logic_field{}
{

    m_texture_tiles.loadFromFile("resources//img//tiles.jpg");

    // �������� �������� ������ ������ � ��������
    for (int32_t s{}; s < m_sprite_tiles.size(); ++s) {
        m_sprite_tiles.at(s).setTexture(m_texture_tiles);
        m_sprite_tiles.at(s).setTextureRect(sf::IntRect(s * 32, 0, 32, 32));
    }

    // ���������� ��� ������ �� ������� ����
    for (int32_t x{}; x < m_fill_field.size(); ++x) {
        for (int32_t y{}; y < m_fill_field.size(); ++y) {
            // ��������� ������ ������ ���������� ������� (���������� �����). 0 - ��� ����, 9 - ������ ���
            if (std::mt19937(std::random_device {}())() % 6 == 0) m_logic_field.at(x).at(y) = 9;
            // � ������� ����� �������� ���� (������� �����) ��� ������ ��������
            m_fill_field.at(x).at(y) = 10;
        }
    }

    // ��� ������ ������ ����������� ���-�� ��� ����� � ��� (������� 3x3)
    for (int32_t x{}; x < m_fill_field.size(); ++x) {
        for (int32_t y{}; y < m_fill_field.size(); ++y) {

            // ���� � ������ ���� ����, �� �� �� ��������� � ��������� � ���������
            if (m_logic_field.at(x).at(y) == 9) continue;

            // ��������� ������ ������ ��� ���� ���������� ������� 3x3 �� ������� ���
            for (int32_t i{x - 1}; i <= x + 1; ++i)
                for (int32_t j{y - 1}; j <= y + 1; ++j)
                    // ���� ������ ������ ���������� ������� ������� ������ �� ������� �� ������� ���� � ����� ����, ���������� +1
                    if (check_cell(i, j) && m_logic_field.at(i).at(j) == 9) m_logic_field.at(x).at(y)++;
        }
    }
}

bool Sapper::check_cell(int32_t &cell_1, int32_t &cell_2) const
{
    if (cell_1 >= 0 && cell_2 >= 0 && cell_1 < m_logic_field.size() && cell_2 < m_logic_field.size()) return true;
    else return false;
}

void Sapper::replace_fill_sprite(int32_t x_mouse, int32_t y_mouse, int32_t value)
{
    for (int32_t x{}; x < m_fill_field.size(); ++x)
        for (int32_t y{}; y < m_fill_field.size(); ++y)
            if (x_mouse == x && y_mouse == y) m_fill_field.at(x).at(y) = value;
}

std::array<std::array<int32_t, 20>, 20> Sapper::get_fill_field() const
{
    return m_fill_field;
}

std::array<std::array<int32_t, 20>, 20> Sapper::get_logic_field() const
{
    return m_logic_field;
}

std::array<sf::Sprite, 12> Sapper::get_sprite_tiles() const
{
    return m_sprite_tiles;
}
