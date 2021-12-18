#pragma once
#include <SFML/Graphics.hpp>

namespace hd {

	class Snake
	{
	public:
		Snake(int x, int y);
		~Snake();


	private:
		int m_x, m_y, m_x0, m_y0;
		

		sf::Texture m_texture;
		sf::Sprite* m_bird = nullptr;




	};




}