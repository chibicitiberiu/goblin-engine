#include "GameWindow.h"

namespace Goblin
{

	GameWindow::GameWindow(void)
	{
		this->setUp();
	}


	GameWindow::~GameWindow(void)
	{
	}

	void GameWindow::setUp()
	{
		// Set up main layout
		mainLayout = sfg::Table::Create();

		// Set up window
		window = sfg::Window::Create();
		window->SetStyle(sfg::Window::NO_STYLE);
		window->Add(mainLayout);
	}
}