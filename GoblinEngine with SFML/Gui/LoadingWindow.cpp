#include "LoadingWindow.h"
#include "../Core/Clamp.h"

namespace Goblin
{
	namespace Gui
	{

		LoadingWindow::LoadingWindow(void)
		{
			this->setUp();
		}


		LoadingWindow::~LoadingWindow(void)
		{
		}

		void LoadingWindow::setUp()
		{
			// Set up message label
			message = sfg::Label::Create("Loading...");
			message->SetAlignment(sf::Vector2f(0, 0));

			// Set up progress bar
			progressBar = sfg::ProgressBar::Create();
			progressBar->SetFraction(0.0f);
		
			// Set up button
			cancelButton = sfg::Button::Create("Cancel");
			cancelButton->GetSignal(sfg::Button::OnLeftClick).Connect(&LoadingWindow::cancelClicked, this);

			// Set up progress layout
			progressLayout = sfg::Box::Create(sfg::Box::HORIZONTAL, 2.0f);
			progressLayout->Pack(progressBar);
			progressLayout->Pack(cancelButton, false, false);

			// Set up main layout
			layout = sfg::Box::Create(sfg::Box::VERTICAL, 2.0f);
			layout->Pack(message);
			layout->Pack(progressLayout);

			// Set up window
			this->setTitle("Loading");
			this->setIsResizable(false);
			this->setMinSize(320, 100);
			this->getWindowPtr()->Add(layout);
		}

		void LoadingWindow::cancelClicked()
		{
			this->setDialogResult(Window::Cancel);
			this->close();
		}

		void LoadingWindow::setProgress(float percent)
		{
			progressBar->SetFraction(clamp(percent, 0.0f, 1.0f));
		}

		void LoadingWindow::setMessage(const sf::String& value)
		{
			message->SetText(value);
		}

		float LoadingWindow::getProgress() const
		{
			return progressBar->GetFraction();
		}

		sf::String LoadingWindow::getMessage() const
		{
			return message->GetText();
		}
	}
}