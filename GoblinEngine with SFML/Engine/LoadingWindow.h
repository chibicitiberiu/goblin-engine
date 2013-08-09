#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	class DLLEXPORT LoadingWindow
	{
	private:

		sfg::Window::Ptr window;
		sfg::Box::Ptr layout;
		sfg::Box::Ptr progressLayout;
		sfg::Label::Ptr message;
		sfg::ProgressBar::Ptr progressBar;
		sfg::Button::Ptr cancelButton;

		void setUp();
		void cancelClicked();

	public:
		LoadingWindow(void);
		virtual ~LoadingWindow(void);

		sfg::Window::Ptr getWindowPtr();
	};
}