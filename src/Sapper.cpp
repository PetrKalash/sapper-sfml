#include "Sapper.h"

Sapper::Sapper() : m_fill_field{}
{
    // ��������� ����������� ������� �����
    m_texture_tiles.loadFromFile("resources//img//tiles.jpg");
    m_sprite_tiles.setTexture(m_texture_tiles);

    // ��������� ������ ������ �� ������� ���� ���������� �������
    for (size_t x{}; x < 10; ++x)
        for (size_t y{}; y < 10; ++y)
            m_logic_field.at(x).at(y) = std::mt19937(std::random_device {}())() % 6;
}

void Sapper::add_sprite_tiles()
{
    // �������� ����������� ������
    m_sprite_tiles.setTextureRect(sf::IntRect(320, 0, 32, 32));
    // ������������� ���������� ��� ������ ������
    m_sprite_tiles.setPosition(32, 32);
}

sf::Sprite Sapper::get_sprite_tiles() const
{
    return m_sprite_tiles;
}