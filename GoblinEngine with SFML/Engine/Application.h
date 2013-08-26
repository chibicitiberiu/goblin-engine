#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "../Gui/GuiController.h"
#include "GameController.h"

namespace Goblin {

	class DLLEXPORT Application {

	protected:

		sf::RenderWindow mainWindow;
		sf::Color background;

		GuiController gui;

		float fps;

	protected:

		volatile bool stop_flag;

		// Main application events
		virtual bool initialize();
		virtual void onMainWindowEvent(sf::Event&);
		virtual void onStart();
		virtual void onLogicUpdate(sf::Time&);
		virtual void onClose();
		
		// Render events
		virtual void onRenderBegin(sf::Time&);
		virtual void onRenderEnd(sf::Time&);
		virtual void onRender(sf::Time&);

		// UI Events
		virtual void onKeyDown(sf::Event&);
		virtual void onResized(sf::Event&);

		// Close

	private:

	public:
		Application();

		virtual int main();
		virtual void stop();

		virtual ~Application() { }
	};

}