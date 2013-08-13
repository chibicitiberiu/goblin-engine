#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"
#include "Widget.h"
#include "IContainer.h"

namespace Goblin
{
	namespace Gui
	{
		class DLLEXPORT Window : public Widget, public IContainer
		{
		public:

			enum DialogResult {
				None,
				OK,
				Cancel,
				Apply
			};

		private:
			bool closed;
			DialogResult result;
			sfg::Window::Ptr window;

			// Initialization
			void setUp();

			// Setters
			void setStyleBit(bool value, int bit);

		protected:
			// Setters
			virtual void setDialogResult(DialogResult value);

		public:

			Window();
			Window(sfg::Window::Ptr w);
			virtual ~Window();

			// State
			virtual void show();
			virtual void close();

			// Children (todo)
			virtual void addChild(const Widget& child);

			// Setters
			virtual void setHasBackground(bool value);
			virtual void setHasShadow(bool value);
			virtual void setHasTitleBar(bool value);
			virtual void setIsResizable(bool value);
			virtual void setTitle(const sf::String& value);

			// Getters
			virtual DialogResult getDialogResult() const;
			virtual sf::String getTitle() const;
			virtual sfg::Window::Ptr getWindowPtr() const;
			virtual bool hasBackground() const;
			virtual bool hasShadow() const;
			virtual bool hasTitleBar() const;
			virtual bool isClosed() const;
			virtual bool isResizable() const;
		};

	}
}