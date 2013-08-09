#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

#include <vector>
#include "../Core/Build.h"

namespace Goblin {

	class DLLEXPORT Application {

	private:

		sf::RenderWindow mainWindow;
		sfg::SFGUI sfgui;
		sfg::Desktop sfdesktop;
		sfg::Window::Ptr sfwindow;
		sfg::Button::Ptr lebutton;
		sfg::Label::Ptr lelabel;
		sfg::Box::Ptr boxlayout;

		void onButtonClicked();

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