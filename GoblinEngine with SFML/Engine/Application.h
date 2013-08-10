#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "GuiController.h"
#include "GameController.h"

namespace Goblin {

	class DLLEXPORT Application {

	private:

		sf::RenderWindow mainWindow;
		GuiController gui;
		GameController game;

		float fps;

	protected:

		volatile bool stop_flag;

		// Main application parts
		virtual bool initialize();
		virtual void onMainWindowEvent(sf::Event&);
		virtual void onStart();
		virtual void onLogicUpdate(sf::Time&);
		virtual void onRender(sf::Time&);
		virtual void dispose();

		// Events
		virtual void onKeyDown(sf::Event&);
		virtual void onResized(sf::Event&);

	private:

	public:
		Application();

		virtual int main();
		virtual void stop();

		virtual ~Application() { }
	};

}