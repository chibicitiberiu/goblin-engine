#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	class DLLEXPORT SettingsWindow
	{
		private:
			sfg::Window::Ptr window;
			sfg::Notebook::Ptr pages;
			sfg::Box::Ptr mainLayout;
			sfg::Box::Ptr buttonsLayout;
			sfg::Button::Ptr okButton;
			sfg::Button::Ptr cancelButton;
			sfg::Button::Ptr applyButton;
			sfg::Widget::Ptr filler;

			bool dialogResult, finished;

			void setUp();
			void okClicked();
			void cancelClicked();
			void applyClicked();

		public:
			SettingsWindow(void);
			virtual ~SettingsWindow(void);

			void addCategory(sfg::Widget::Ptr& mainWidget, sfg::Widget::Ptr& label);

			sfg::Window::Ptr getWindowPtr();
	};
}