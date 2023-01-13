#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Sapper
{
protected:
    static sf::Texture m_texture_tiles;
    static sf::Sprite m_sprite_tiles;

private:
    std::array<std::array<int32_t, 10>, 10> m_fill_field;     // ��������������� ����
    std::array<std::array<int32_t, 10>, 10> m_logic_field;    // ������� ������ ����

public:
    Sapper();
    void print();
};