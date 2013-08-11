#pragma once
#include <SFGUI/SFGUI.hpp>
#include "Window.h"

namespace Goblin
{
	namespace Gui
	{
		class DLLEXPORT LoadingWindow : public Window
		{
		private:

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

			// Setters
			virtual void setProgress(float percent);
			virtual void setMessage(const sf::String& value);

			// Getters
			virtual float getProgress() const;
			virtual sf::String getMessage() const;
		};
	}
}