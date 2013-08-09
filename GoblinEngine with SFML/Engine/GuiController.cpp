#include "GuiController.h"

namespace Goblin
{

	GuiController::GuiController(void)
	{
		desktop.Add(this->console.getWindowPtr());
		desktop.Add(this->loading.getWindowPtr());
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
				console.setVisible(!console.isVisible());
				break;

			default:
				break;
		}
	}

	void GuiController::onResized(sf::Event& e)
	{
		console.resize(static_cast<float>(e.size.width), 200);
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

	ConsoleWindow* GuiController::getConsoleWindow()
	{
		return &this->console;
	}
}