#include "Window.h"

namespace Goblin
{
	namespace GUI
	{
		Window::Window(void)
			: closed(true), result(Window::None)
		{
			this->setUp();
		}


		Window::~Window(void)
		{
		}

		void Window::setUp()
		{
			// Set up window
			window = sfg::Window::Create();
			window->Show(false);
		}

		void Window::setDialogResult(DialogResult value)
		{
			this->result = value;
		}

		void Window::show()
		{
			this->closed = false;
			window->Show(true);
		}

		void Window::close()
		{
			this->closed = true;
			window->Show(false);
		}

		bool Window::isClosed() const
		{
			return this->closed;
		}

		Window::DialogResult Window::getDialogResult() const 
		{
			return this->result;
		}
		
		sfg::Window::Ptr Window::getWindowPtr() const
		{
			return this->window;
		}

		void Window::setTitle(const sf::String& value)
		{
			window->SetTitle(value);
		}

		sf::String Window::getTitle() const
		{
			return window->GetTitle();
		}
	}
}