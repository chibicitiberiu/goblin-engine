#include "ConsoleWindow.h"

namespace Goblin
{
	namespace Gui
	{
		ConsoleWindow::ConsoleWindow()
			: Window()
		{
			this->setUp();
		}

		ConsoleWindow::~ConsoleWindow()
		{
		}

		void ConsoleWindow::submitPressed()
		{
			if (!entryText->GetText().isEmpty())
			{
				this->addText("] " + entryText->GetText() + "\n");
				entryText->SetText("");
			}
		}

		void ConsoleWindow::keyPressed()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				submitPressed();
		}

		void ConsoleWindow::setUp()
		{
			// Set up label
			text = sfg::Label::Create();
		
			// Set up scroll area
			scrollArea = sfg::ScrolledWindow::Create();
			scrollArea->SetScrollbarPolicy(sfg::ScrolledWindow::HORIZONTAL_NEVER | sfg::ScrolledWindow::VERTICAL_ALWAYS);
			scrollArea->AddWithViewport(text);

			// Set up entry text box
			entryText = sfg::Entry::Create();
			entryText->GetSignal(sfg::Button::OnKeyPress).Connect(&ConsoleWindow::keyPressed, this);

			// Set up entry button
			entryButton = sfg::Button::Create("Submit");
			entryButton->GetSignal(sfg::Button::OnLeftClick).Connect(&ConsoleWindow::submitPressed, this);

			// Set up entry layout
			entryAreaLayout = sfg::Box::Create(sfg::Box::HORIZONTAL, 2.0f);
			entryAreaLayout->Pack(entryText);
			entryAreaLayout->Pack(entryButton, false, false);

			// Set up main layout
			layout = sfg::Box::Create(sfg::Box::VERTICAL, 2.0f);
			layout->Pack(scrollArea);
			layout->Pack(entryAreaLayout, false, false);

			// Set up window
			this->setHasBackground(true);
			this->setHasTitleBar(false);
			this->setIsResizable(false);
			this->setTitle("Console");
			this->getWindowPtr()->Add(layout);
		}

		void ConsoleWindow::addText(sf::String txt)
		{
			text->SetText(text->GetText() + txt);
			auto vp = scrollArea->GetVerticalAdjustment();
			vp->SetValue(vp->GetUpper());
		}

	}
}