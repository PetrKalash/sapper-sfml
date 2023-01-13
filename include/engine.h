#pragma once
#include <SFML/Graphics.hpp>
#include "sapper.h"

class Engine
{
private:
	sf::RenderWindow main_window;	// главное окно
	Sapper m_sapper;				// экземляр сапера

public:
	Engine();

	// Запуск программы
	void start_game();
	// Обработка событий
	void event_processing();
	// Логика игры
	void sapper_game();
	// Отрисовка окна
	void draw_window();
};