#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	class DLLEXPORT ConsoleWindow
	{
	private:
		
		sfg::Window::Ptr window;
		sfg::Box::Ptr layout;
		sfg::Box::Ptr entryAreaLayout;
		sfg::ScrolledWindow::Ptr scrollArea;
		sfg::Label::Ptr text;
		sfg::Entry::Ptr entryText;
		sfg::Button::Ptr entryButton;

		void setUp();

	private:
		void submitPressed();
		void keyPressed();

	public:
		ConsoleWindow();
		~ConsoleWindow();

		sfg::Window::Ptr getWindowPtr();
		void addText(sf::String txt);

		bool isVisible();
		void setVisible(bool value);
		void resize(float x, float y);
	};

}