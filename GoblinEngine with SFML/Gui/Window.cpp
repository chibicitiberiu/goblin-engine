#include "Window.h"

namespace Goblin
{
	namespace Gui
	{
		/***********************************
		 * Constructor, destructor         *
		 ***********************************/
		Window::Window(void)
			: closed(true), result(Window::None)
		{
			this->setUp();
		}

		Window::Window(sfg::Window::Ptr w)
			: window(w), closed(true), result(Window::None)
		{
			closed = this->isVisible();
		}

		Window::~Window(void)
		{
		}

		/***********************************
		 * Initialization                  *
		 ***********************************/
		void Window::setUp()
		{
			// Set up window
			window = sfg::Window::Create();
			window->Show(false);
			window->SetStyle(sfg::Window::TITLEBAR | sfg::Window::RESIZE | sfg::Window::BACKGROUND);

			this->setWidget(window);
		}

		/***********************************
		 * Getters                         *
		 ***********************************/
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

		sf::String Window::getTitle() const
		{
			return window->GetTitle();
		}

		bool Window::hasTitleBar() const
		{
			return (window->GetStyle() & sfg::Window::TITLEBAR) > 0;
		}

		bool Window::hasBackground() const
		{
			return (window->GetStyle() & sfg::Window::BACKGROUND) > 0;
		}

		bool Window::isResizable() const
		{
			return (window->GetStyle() & sfg::Window::RESIZE) > 0;
		}

		bool Window::hasShadow() const
		{
			return (window->GetStyle() & sfg::Window::SHADOW) > 0;
		}

		/***********************************
		 * Setters                         *
		 ***********************************/
		void Window::setDialogResult(DialogResult value)
		{
			this->result = value;
		}

		void Window::setStyleBit(bool value, int bit)
		{
			int style = window->GetStyle();

			if (value) 
				window->SetStyle(style | bit);

			else
				window->SetStyle(style & (~bit));
		}

		void Window::setTitle(const sf::String& value)
		{
			window->SetTitle(value);
		}

		void Window::setHasTitleBar(bool value)
		{
			this->setStyleBit(value, sfg::Window::TITLEBAR);
		}

		void Window::setHasBackground(bool value)
		{
			this->setStyleBit(value, sfg::Window::BACKGROUND);
		}

		void Window::setIsResizable(bool value)
		{
			this->setStyleBit(value, sfg::Window::RESIZE);
		}

		void Window::setHasShadow(bool value)
		{
			this->setStyleBit(value, sfg::Window::SHADOW);
		}

		/***********************************
		 * Window state                    *
		 ***********************************/
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

		/***********************************
		 * Children                        *
		 ***********************************/
		void Window::addChild(const Widget& child)
		{
			this->window->Add(child.getWidgetPtr());
		}
	}
}