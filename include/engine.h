#pragma once
#include <SFML/Graphics.hpp>

class Engine
{
private:
	sf::RenderWindow main_window;

public:
	Engine();
	void start_game();
};