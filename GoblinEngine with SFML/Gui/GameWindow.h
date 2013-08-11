#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{

	class GameWindow
	{
	private:
		sfg::Window::Ptr window;

		sfg::Table::Ptr mainLayout;
		

		void setUp();

	public:
		GameWindow(void);
		virtual ~GameWindow(void);
	};

}