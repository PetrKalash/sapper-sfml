#include "engine.h"

Engine::Engine()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    main_window.create(sf::VideoMode(320, 320), "Sapper", sf::Style::Default, settings);

    m_texture_background.loadFromFile("resources//img//background.jpg");
    m_sprite_backround.setTexture(m_texture_background);
}

void Engine::start_game()
{
    while (main_window.isOpen()) 
    {
        event_processing();
        sapper_game();
        draw_window();
    }
}

void Engine::event_processing()
{
    // �������� ���������� ������� ����� ������������ �������� ���� ����������
    sf::Vector2i pos = sf::Mouse::getPosition(main_window);
    int32_t x_mouse = pos.x / 32;
    int32_t y_mouse = pos.y / 32;

    std::array<sf::Sprite, 12> sprite = m_sapper.get_sprite_tiles();            // ������ ������
    std::array<std::array<int32_t, 10>, 10> fill = m_sapper.get_fill_field();   // �������� ������
    std::array<std::array<int32_t, 10>, 10> logic = m_sapper.get_logic_field(); // ���������� �����

    sf::Event e;
    while (main_window.pollEvent(e))
    {
        // �������� ���� ����� ������� �� �������
        if (e.type == sf::Event::Closed) main_window.close();

        // ��������� ������� ������ ����
        if (e.type == sf::Event::MouseButtonPressed) 
        {
            // ��������� ������ ��� ������� ������ ������� ����
            if (e.key.code == sf::Mouse::Right) {
                // ���� ���� �� �����, ������ �� ��������� �������
                if (fill.at(x_mouse).at(y_mouse) == 10) {
                    m_sapper.replace_fill_sprite(x_mouse, y_mouse, 11);
                }
                // ���� ���� ��� �����, �� ����� ������� ������ ������ ���� �� ���������
                else if (fill.at(x_mouse).at(y_mouse) == 11) {
                    m_sapper.replace_fill_sprite(x_mouse, y_mouse, 10);
                }
            }
            
            // ��������� �������� ������ ����� ������� ����
            if (e.key.code == sf::Mouse::Left)
            {
                for (int32_t x{}; x < logic.size(); ++x) {
                    for (int32_t y{}; y < logic.size(); ++y) {

                        // ���� �� ����� ����, ��������� �� � ����������� ����
                        if (logic.at(x_mouse).at(y_mouse) == 9) {
                            for (int32_t x{}; x < logic.size(); ++x)
                                for (int32_t y{}; y < logic.size(); ++y)
                                    m_sapper.replace_fill_sprite(x, y, logic.at(x).at(y));
                        }

                        // ���� �� ������� ������ �����, ��������� ��������� � ��� ������
                        if (logic.at(x_mouse).at(y_mouse) == 0) {
                            for (int32_t x{}; x < logic.size(); ++x)
                                for (int32_t y{}; y < logic.size(); ++y)
                                    // ��������� ������ ��� ������� �� ��� ���, ���� �� ������� ������ ��� ������
                                    if (logic.at(x).at(y) == 0) m_sapper.replace_fill_sprite(x, y, logic.at(x).at(y));
                        }

                        // �������� ������ ������� ������ �� ������ ���������� ������ (��������� ��)
                        m_sapper.replace_fill_sprite(x_mouse, y_mouse, logic.at(x_mouse).at(y_mouse));
                    }
                }
            }
        }
    }
}

void Engine::sapper_game()
{

}

void Engine::draw_window()
{
    std::array<sf::Sprite, 12> sprite = m_sapper.get_sprite_tiles();            // ������ ������
    std::array<std::array<int32_t, 10>, 10> fill = m_sapper.get_fill_field();   // �������� ������

    // ��������� ������� ����
    main_window.clear(sf::Color::White);
    main_window.draw(m_sprite_backround);

    // ������ ��������� �������� ����
    for (int32_t x{}; x < fill.size(); ++x) {
        for (int32_t y{}; y < fill.size(); ++y) {
            // ������������� ���������� ��� ������ ������
            sprite.at(fill.at(x).at(y)).setPosition(x * 32, y * 32);
            // ��� ������ ������ ����������� ���� ������
            main_window.draw(sprite.at(fill.at(x).at(y)));
        }
    }

    // ������ ����������� ����
    main_window.display();
}