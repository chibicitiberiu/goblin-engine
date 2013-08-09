#include "ConsoleWindow.h"

namespace Goblin
{
	ConsoleWindow::ConsoleWindow()
	{
		this->setUp();
	}

	ConsoleWindow::~ConsoleWindow()
	{
	}

	void ConsoleWindow::submitPressed()
	{
		this->addText("] " + entryText->GetText() + "\n");
		entryText->SetText("");
	}

	void ConsoleWindow::keyPressed()
	{
	}

	void ConsoleWindow::setUp()
	{
		// Create label
		text = sfg::Label::Create();
		
		// Create scroll area
		scrollArea = sfg::ScrolledWindow::Create();
		scrollArea->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER | sfg::ScrolledWindow::VERTICAL_ALWAYS);
		scrollArea->AddWithViewport(text);

		// Create entry text box
		entryText = sfg::Entry::Create();
		entryText->GetSignal(sfg::Button::OnKeyPress).Connect(&ConsoleWindow::keyPressed, this);

		// Create entry button
		entryButton = sfg::Button::Create("Submit");
		entryButton->GetSignal(sfg::Button::OnLeftClick).Connect(&ConsoleWindow::submitPressed, this);

		// Create entry layout
		entryAreaLayout = sfg::Box::Create(sfg::Box::HORIZONTAL, 2.0f);
		entryAreaLayout->Pack(entryText);
		entryAreaLayout->Pack(entryButton, false, false);

		// Create main layout
		layout = sfg::Box::Create(sfg::Box::VERTICAL, 2.0f);
		layout->Pack(scrollArea);
		layout->Pack(entryAreaLayout, false, false);

		// Create window
		window = sfg::Window::Create();
		window->SetStyle(sfg::Window::BACKGROUND);
		window->SetTitle("Console");
		window->Show(false);
		window->Add(layout);
	}

	sfg::Window::Ptr ConsoleWindow::getWindowPtr()
	{
		return this->window;
	}

	void ConsoleWindow::addText(sf::String txt)
	{
		text->SetText(text->GetText() + txt);
		auto vp = scrollArea->GetVerticalAdjustment();
		vp->SetValue(vp->GetUpper());
	}

	bool ConsoleWindow::isVisible()
	{
		return this->window->IsGloballyVisible();
	}

	void ConsoleWindow::setVisible(bool value)
	{
		this->window->Show(value);
	}

	void ConsoleWindow::resize(float x, float y)
	{
		this->window->SetAllocation(sf::FloatRect(0, 0, x, y));
	}
}