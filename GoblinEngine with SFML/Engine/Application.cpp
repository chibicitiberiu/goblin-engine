#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../Core/Log.h"
#include "DebugHandlers.h"

namespace Goblin
{
	/***********************************
	 * Constructor                     *
	 ***********************************/
	Application::Application()
		: game(1000, 1000)
	{
		this->stop_flag = false;
		this->fps = 0;
	}

	/***********************************
	 * Initialize, dispose             *
	 ***********************************/
	bool Application::initialize()
	{
		// Initialize debugging
		debug.addHandler(new WinAPIDebugHandler());
		debug.addHandler(new StdOutDebugHandler());
		debug.addHandler(new ConsoleDebugHandler(this->gui.getConsoleWindow()));

		// Create window
		this->mainWindow.create(sf::VideoMode(100, 100), "Goblin engine");
		this->mainWindow.setSize(sf::Vector2u(640, 480));
		
		// Prepare for rendering
		this->mainWindow.resetGLStates();

		return true;
	}

	void Application::onStart()
	{
	}

	void Application::dispose()
	{
	}

	/***********************************
	 * Main loop (run)                 *
	 ***********************************/
	int Application::main()
	{
		// Initialize
		if (!this->initialize())
		{
			this->dispose();
			return -1;
		}

		sf::Clock clock;

		// Before start handler
		this->onStart();

		// Main loop
		while (!this->stop_flag)
		{
			// Get elapsed time
			sf::Time elapsed = clock.restart();

			// Handle events
			sf::Event event;
			while (this->mainWindow.pollEvent(event))
				this->onMainWindowEvent(event);

			// Update logic
			onLogicUpdate(elapsed);

			// Update graphics
			onRender(elapsed);
		}

		// Cleanup
		this->dispose();
		return 0;
	}

	void Application::stop()
	{
		this->mainWindow.close();
		this->stop_flag = true;
	}

	/***********************************
	 * Event handler                   *
	 ***********************************/
	void Application::onMainWindowEvent(sf::Event& e)
	{
		gui.onEvent(e);

		switch (e.type)
		{
			case sf::Event::Closed :
				this->stop();
				break;

			case sf::Event::KeyPressed:
				this->onKeyDown(e);
				break;

			case sf::Event::Resized:
				this->onResized(e);
				break;

			default:
				break;
		}
	}

	void Application::onKeyDown(sf::Event& e)
	{
		switch(e.key.code)
		{
			case sf::Keyboard::Escape:
				this->stop();
				break;

			default:
				break;
		}

		// Update gui
		gui.onKeyDown(e);
	}

	void Application::onResized(sf::Event& e)
	{
		// Update view
		sf::Vector2f center((float)e.size.width / 2, (float)e.size.height / 2);
		sf::Vector2f size((float)e.size.width, (float)e.size.height);
		sf::View view(center, size);

		this->mainWindow.setView(view);

		// Update gui
		gui.onResized(e);
	}


	/***********************************
	 * Renderer                        *
	 ***********************************/
	void Application::onRender(sf::Time& elapsed)
	{
		mainWindow.clear(sf::Color::Black);
		
		
		// Render gui
		gui.onRender(mainWindow, elapsed);

		mainWindow.display();
	}

	/***********************************
	 * Game logic                      *
	 ***********************************/
	void Application::onLogicUpdate(sf::Time& elapsed)
	{
		// Update gui
		gui.onLogicUpdate(elapsed);

		this->fps = (this->fps + (1.0f / elapsed.asSeconds()) ) / 2.0f;
	}


}