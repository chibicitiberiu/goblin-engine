#include "LoadingWindow.h"

namespace Goblin
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
		progressBar->SetFraction(0.3f);
		
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
		window = sfg::Window::Create();
		window->SetTitle("Loading");
		window->SetStyle(sfg::Window::TITLEBAR | sfg::Window::BACKGROUND);
		window->Add(layout);
		window->SetAllocation(sf::FloatRect(50, 50, 400, 100));
	}

	void LoadingWindow::cancelClicked()
	{
	}

	sfg::Window::Ptr LoadingWindow::getWindowPtr()
	{
		return this->window;
	}
}