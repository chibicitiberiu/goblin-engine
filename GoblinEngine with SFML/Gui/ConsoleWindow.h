#pragma once
#include "Window.h"

namespace Goblin
{
	namespace Gui
	{

		class DLLEXPORT ConsoleWindow : public Window
		{
		private:
		
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

			void addText(sf::String txt);
		};

	}
}