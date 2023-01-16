#pragma once
#include <SFML/Graphics.hpp>
#include "sapper.h"

class Engine
{
public:
	// ��������� ������� ������ ����
	enum class Mouse
	{
		LEFT_CLICK,						// ����� ������ ����
		RIGHT_CLICK,					// ������ ������ ����
		MAX_MOUSE_VALUES				// ������������ ��������
	};

protected:
	sf::Texture m_texture_background;   // �������� ������� ���� ������
	sf::Sprite m_sprite_backround;		// ������ ������� ���� ������

private:
	sf::RenderWindow main_window;		// ������� ����
	Sapper m_sapper;					// ��������� ������

	// ��������� �������
	void event_processing();
	// ������ ����
	void sapper_game(Mouse mouse_click);
	// ��������� ����
	void draw_window();

public:
	Engine();

	// ������ ���������
	void start_game();
};