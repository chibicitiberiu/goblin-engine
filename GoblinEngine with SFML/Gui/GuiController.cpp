#include "GuiController.h"

namespace Goblin
{

	GuiController::GuiController(void)
	{
		desktop.Add(this->console.getWindowPtr());
		desktop.Add(this->loading.getWindowPtr());
		desktop.Add(this->settings.getWindowPtr());

		this->settings.addCategory(this->videoSettingsPage.getMainWidget(), this->videoSettingsPage.getTitleWidget());
		this->loading.show();
	}


	GuiController::~GuiController(void)
	{
	}

	void GuiController::onEvent(sf::Event& e)
	{
		desktop.HandleEvent(e);
	}

	void GuiController::onKeyDown(sf::Event& e)
	{
		switch(e.key.code)
		{
			case sf::Keyboard::Tilde:
				if (console.isClosed())
					console.show();
				else
					console.close();
				break;

			case sf::Keyboard::A:
				this->loading.setProgress(this->loading.getProgress() + 0.01f);
				break;

			case sf::Keyboard::S:
				this->loading.setProgress(this->loading.getProgress() - 0.01f);
				break;

			default:
				break;
		}
	}

	void GuiController::onResized(sf::Event& e)
	{
		console.setSize(static_cast<float>(e.size.width), 200);
	}

	void GuiController::onRender(sf::RenderTarget& target, const sf::Time& elapsed)
	{
		sf::RenderWindow* wnd = dynamic_cast<sf::RenderWindow*>(&target);
		sf::RenderTexture* text = dynamic_cast<sf::RenderTexture*>(&target);

		if (wnd != NULL)
			sfgui.Display(*wnd);

		else if (text != NULL)
			sfgui.Display(*text);
	}

	void GuiController::onLogicUpdate(const sf::Time& elapsed)
	{
		desktop.Update(elapsed.asSeconds());
	}

	Gui::ConsoleWindow* GuiController::getConsoleWindow()
	{
		return &this->console;
	}
}