#include "engine.h"

Engine::Engine()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    main_window.create(sf::VideoMode(640, 640), "Sapper", sf::Style::Default, settings);

    m_texture_background.loadFromFile("resources//img//background.jpg");
    m_sprite_backround.setTexture(m_texture_background);
}

void Engine::start_game()
{
    while (main_window.isOpen()) 
    {
        event_processing();
        draw_window();
    }
}

void Engine::event_processing()
{
    sf::Event e;
    while (main_window.pollEvent(e))
    {
        // �������� ���� ����� ������� �� �������
        if (e.type == sf::Event::Closed) main_window.close();

        // ��������� ������� ������ ����
        if (e.type == sf::Event::MouseButtonPressed) 
        {
            // ��������� ��� ��������� ������ ��� ������� ������ ������� ����
            if (e.key.code == sf::Mouse::Right) sapper_game(Mouse::RIGHT_CLICK);
            // ��������� �������� ������ ����� ������� ����
            if (e.key.code == sf::Mouse::Left) sapper_game(Mouse::LEFT_CLICK);
        }
    }
}

void Engine::sapper_game(Mouse mouse_click)
{
    // �������� ���������� ������� ����� ������������ �������� ���� ����������
    sf::Vector2i pos = sf::Mouse::getPosition(main_window);
    int32_t x_mouse = pos.x / 32;
    int32_t y_mouse = pos.y / 32;

    std::array<std::array<int32_t, 20>, 20> fill = m_sapper.get_fill_field();   // �������� ������
    std::array<std::array<int32_t, 20>, 20> logic = m_sapper.get_logic_field(); // ���������� �����

    switch (mouse_click)
    {
        case Mouse::RIGHT_CLICK:
        {
            // ���� ���� �� �����, ������ �� ��������� �������
            if (fill.at(x_mouse).at(y_mouse) == 10) {
                m_sapper.replace_fill_sprite(x_mouse, y_mouse, 11);
            }
            // ���� ���� ��� �����, �� ����� ������� ������ ������ ���� �� ���������
            else if (fill.at(x_mouse).at(y_mouse) == 11) {
                m_sapper.replace_fill_sprite(x_mouse, y_mouse, 10);
            } break;
        }

        case Mouse::LEFT_CLICK:
        {
            // �������� ������ ������� ������ �� ������ ���������� ������ (��������� ��)
            m_sapper.replace_fill_sprite(x_mouse, y_mouse, logic.at(x_mouse).at(y_mouse));

            // ���� �� ����� ����, ��������� �� � ����������� ����
            if (logic.at(x_mouse).at(y_mouse) == 9) {
                for (int32_t x{}; x < logic.size(); ++x)
                    for (int32_t y{}; y < logic.size(); ++y)
                        m_sapper.replace_fill_sprite(x, y, logic.at(x).at(y));
            } 
            
            // ��������� ������ �������� ������
            std::array<std::array<bool, 20>, 20> check_open{};

            int32_t square_cells{1};
            int32_t count{0};

            if (logic.at(x_mouse).at(y_mouse) == 0) {
                // ���������� �� ��� ���, ���� �� ��������� �� ����� ����
                while (square_cells < logic.size())
                {
                    // ���������� ��� ������ �� ������� ���� �� ��� ���, ���� �� ������� ��� ����������� ����� ������
                    for (int32_t x {x_mouse - square_cells}; x <= x_mouse + square_cells; ++x) {
                        for (int32_t y {y_mouse - square_cells}; y <= y_mouse + square_cells; ++y) {

                            // �������� �� ����� �� �������
                            if (x >= 0 && y >= 0 && x < logic.size() && y < logic.size()) {
                                // ���� ������� ������ ������, ��������� ��������� ������ �� ��� ���, ���� ������ �� ����� ������� �����
                                if (logic.at(x).at(y) == 0 && (check_open.at(x).at(y) || count == 0)) {

                                    count++;
                                    // ��������� ������ ��������� ������ ������� 3x3
                                    for (int32_t i {x - 1}; i <= x + 1; ++i)
                                        for (int32_t j {y - 1}; j <= y + 1; ++j)
                                            // ��������, ��� ������ �� ������� �� ������� �������� ����
                                            if (i >= 0 && j >= 0 && i < logic.size() && j < logic.size()) {
                                                check_open.at(i).at(j) = true;
                                                // ��������� ��� ������ ������ ������ ������
                                                m_sapper.replace_fill_sprite(i, j, logic.at(i).at(j));
                                            }
                                }
                            }
                        }
                    }
                    square_cells++;
                }
            } break;
        }
        default: break;
    }
}

void Engine::draw_window()
{
    std::array<sf::Sprite, 12> sprite = m_sapper.get_sprite_tiles();            // ������ ������
    std::array<std::array<int32_t, 20>, 20> fill = m_sapper.get_fill_field();   // �������� ������

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