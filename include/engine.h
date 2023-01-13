#pragma once
#include <SFML/Graphics.hpp>
#include "sapper.h"

class Engine
{
private:
	sf::RenderWindow main_window;	// ������� ����
	Sapper m_sapper;				// �������� ������

public:
	Engine();

	// ������ ���������
	void start_game();
	// ��������� �������
	void event_processing();
	// ������ ����
	void sapper_game();
	// ��������� ����
	void draw_window();
};