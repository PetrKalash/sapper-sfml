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
    // Получаем координаты курсора мышки относительно главного окна приложения
    sf::Vector2i pos = sf::Mouse::getPosition(main_window);
    int32_t x_mouse = pos.x / 32;
    int32_t y_mouse = pos.y / 32;

    std::array<sf::Sprite, 12> sprite = m_sapper.get_sprite_tiles();            // спрайт ячейки
    std::array<std::array<int32_t, 10>, 10> fill = m_sapper.get_fill_field();   // значение ячейки
    std::array<std::array<int32_t, 10>, 10> logic = m_sapper.get_logic_field(); // внутренняя часть

    sf::Event e;
    while (main_window.pollEvent(e))
    {
        // Закрытие окна после нажатия на крестик
        if (e.type == sf::Event::Closed) main_window.close();

        // Обработка нажатий кнопок мыши
        if (e.type == sf::Event::MouseButtonPressed) 
        {
            // Открываем флажок при нажатии правой кнопкой мыши
            if (e.key.code == sf::Mouse::Right) {
                // Если флаг не стоит, ставим на выбранную позицию
                if (fill.at(x_mouse).at(y_mouse) == 10) {
                    m_sapper.replace_fill_sprite(x_mouse, y_mouse, 11);
                }
                // Если флаг уже стоит, то после нажании правой кнопки мыши он убирается
                else if (fill.at(x_mouse).at(y_mouse) == 11) {
                    m_sapper.replace_fill_sprite(x_mouse, y_mouse, 10);
                }
            }
            
            // Открываем закрытую ячейку левой кнопкой мыши
            if (e.key.code == sf::Mouse::Left)
            {
                for (int32_t x{}; x < logic.size(); ++x) {
                    for (int32_t y{}; y < logic.size(); ++y) {

                        // Если мы нашли мину, открываем ее и заканчиваем игру
                        if (logic.at(x_mouse).at(y_mouse) == 9) {
                            for (int32_t x{}; x < logic.size(); ++x)
                                for (int32_t y{}; y < logic.size(); ++y)
                                    m_sapper.replace_fill_sprite(x, y, logic.at(x).at(y));
                        }

                        // Если мы открыли пустую ячеку, открываем ближайшие с ней ячейки
                        if (logic.at(x_mouse).at(y_mouse) == 0) {
                            for (int32_t x{}; x < logic.size(); ++x)
                                for (int32_t y{}; y < logic.size(); ++y)
                                    // Открываем вокруг нее область до тех пор, пока не откроем вокруг все номера
                                    if (logic.at(x).at(y) == 0) m_sapper.replace_fill_sprite(x, y, logic.at(x).at(y));
                        }

                        // Заменяем спрайт внешней ячейки на спрайт внутренней ячейки (открываем ее)
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
    std::array<sf::Sprite, 12> sprite = m_sapper.get_sprite_tiles();            // спрайт ячейки
    std::array<std::array<int32_t, 10>, 10> fill = m_sapper.get_fill_field();   // значение ячейки

    // Отрисовка заднего фона
    main_window.clear(sf::Color::White);
    main_window.draw(m_sprite_backround);

    // Полная отрисовка игрового поля
    for (int32_t x{}; x < fill.size(); ++x) {
        for (int32_t y{}; y < fill.size(); ++y) {
            // Устанавливаем координаты для каждой ячейки
            sprite.at(fill.at(x).at(y)).setPosition(x * 32, y * 32);
            // Для каждой ячейки отрисовывем свой спрайт
            main_window.draw(sprite.at(fill.at(x).at(y)));
        }
    }

    // Полное отображение поля
    main_window.display();
}