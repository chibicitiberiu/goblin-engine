#include "SettingsWindow.h"

namespace Goblin
{
	SettingsWindow::SettingsWindow(void)
		: dialogResult(false), finished(false)
	{
		this->setUp();
	}


	SettingsWindow::~SettingsWindow(void)
	{
	}

	void SettingsWindow::setUp()
	{
		// Set up notebook
		pages = sfg::Notebook::Create();
	
		// Set up buttons
		okButton = sfg::Button::Create("OK");
		okButton->GetSignal(sfg::Button::OnLeftClick).Connect(&SettingsWindow::okClicked, this);
		okButton->SetRequisition(sf::Vector2f(64, 24));

		cancelButton = sfg::Button::Create("Cancel");
		cancelButton->GetSignal(sfg::Button::OnLeftClick).Connect(&SettingsWindow::cancelClicked, this);
		cancelButton->SetRequisition(sf::Vector2f(64, 24));

		applyButton = sfg::Button::Create("Apply");
		applyButton->GetSignal(sfg::Button::OnLeftClick).Connect(&SettingsWindow::applyClicked, this);
		applyButton->SetRequisition(sf::Vector2f(64, 24));

		// Set up filler
		filler = sfg::Label::Create(" ");
		
		// Set up button layout
		buttonsLayout = sfg::Box::Create(sfg::Box::HORIZONTAL, 2.0f);
		buttonsLayout->Pack(filler);
		buttonsLayout->Pack(okButton, false);
		buttonsLayout->Pack(cancelButton, false);
		buttonsLayout->Pack(applyButton, false);

		// Set up main layout
		mainLayout = sfg::Box::Create(sfg::Box::VERTICAL, 5.0f);
		mainLayout->Pack(pages);
		mainLayout->Pack(buttonsLayout, false);

		// Set up window
		window = sfg::Window::Create();
		window->SetTitle("Settings");
		window->Add(mainLayout);
	}

	void SettingsWindow::addCategory(sfg::Widget::Ptr& mainWidget, sfg::Widget::Ptr& label)
	{
		pages->AppendPage(mainWidget, label);

		sf::Vector2f min_size = mainWidget->GetRequisition();
		sf::FloatRect actual_size = pages->GetAllocation();

		if (min_size.x > actual_size.width || min_size.y > actual_size.height)
		{
			float w = std::max(min_size.x, actual_size.width);
			float h = std::max(min_size.y, actual_size.height);

			pages->SetRequisition(sf::Vector2f(w, h));
		}
	}

	void SettingsWindow::okClicked()
	{
		dialogResult = true;
		finished = true;
	}

	void SettingsWindow::cancelClicked()
	{
		dialogResult = false;
		finished = true;
	}

	void SettingsWindow::applyClicked()
	{
		dialogResult = true;
		finished = false;
	}

	
	sfg::Window::Ptr SettingsWindow::getWindowPtr()
	{
		return window;
	}

}