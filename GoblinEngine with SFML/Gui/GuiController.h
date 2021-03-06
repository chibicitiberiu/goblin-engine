#pragma once
#include <SFGUI/SFGUI.hpp>
#include "ConsoleWindow.h"
#include "LoadingWindow.h"
#include "SettingsWindow.h"
#include "VideoSettingsPage.h"
#include "../Core/Build.h"

namespace Goblin
{
	class DLLEXPORT GuiController
	{
	private:
		sfg::SFGUI sfgui;
		sfg::Desktop desktop;
		Gui::ConsoleWindow console;
		Gui::LoadingWindow loading;
		SettingsWindow settings;
		VideoSettingsPage videoSettingsPage;

	public:
		GuiController();
		virtual ~GuiController();

		virtual void onEvent(sf::Event& e);
		virtual void onKeyDown(sf::Event& e);
		virtual void onResized(sf::Event& e);
		virtual void onRender(sf::RenderTarget& target, const sf::Time& elapsed);
		virtual void onLogicUpdate(const sf::Time& elapsed);

		Gui::ConsoleWindow* getConsoleWindow();
	};
}