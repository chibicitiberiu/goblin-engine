#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	namespace GUI
	{

		class DLLEXPORT Window
		{
		public:

			enum DialogResult {
				None,
				OK,
				Cancel
			};

		private:
			bool closed;
			DialogResult result;

			// Initialization
			void setUp();

		protected:
			sfg::Window::Ptr window;

			// Setters
			virtual void setDialogResult(DialogResult value);


		public:

			Window();
			virtual ~Window();

			// State
			virtual void show();
			virtual void close();

			// Setters
			virtual void setTitle(const sf::String& value);

			// Getters
			virtual bool isClosed() const;
			virtual DialogResult getDialogResult() const;
			virtual sfg::Window::Ptr getWindowPtr() const;
			sf::String getTitle() const;
		};

	}
}