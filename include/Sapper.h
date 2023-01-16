#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Sapper
{
protected:
    sf::Texture m_texture_tiles;                                // ����� �������� �����
    std::array<sf::Sprite, 12> m_sprite_tiles;                  // ������� ������� �����

private:
    std::array<std::array<int32_t, 20>, 20> m_logic_field;        // ������� ������ ����
    std::array<std::array<int32_t, 20>, 20> m_fill_field;         // ��������������� ����

public:
    Sapper();

    // ������ ������ ����� ���������� ��������� ������� ����� ����� ����
    void replace_fill_sprite(int32_t x_mouse, int32_t y_mouse, int32_t value);

    // ����������� ����� ������� ������
    std::array<std::array<int32_t, 20>, 20> get_fill_field() const;
    // ����������� ����� ���������� ������
    std::array<std::array<int32_t, 20>, 20> get_logic_field() const;
    // ����������� ������� ������
    std::array<sf::Sprite, 12> get_sprite_tiles() const;
};