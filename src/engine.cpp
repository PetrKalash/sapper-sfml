#include "engine.h"

Engine::Engine()
{
    main_window.create(sf::VideoMode(400, 400), "Sapper");
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
    sf::Event e;
    while (main_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed) main_window.close();
    }
}

void Engine::sapper_game()
{
    for (size_t x{}; x < 10; ++x) {
        for (size_t y{}; y < 10; ++y) {
            m_sapper.add_sprite_tiles();
        }
    }
}

void Engine::draw_window()
{
    main_window.clear(sf::Color::White);
    main_window.draw(m_sapper.get_sprite_tiles());
    main_window.display();
}