#include "Application.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Goblin
{
	/***********************************
	 * Constructor                     *
	 ***********************************/
	Application::Application()
	{
		this->stop_flag = false;
		this->fps = 0;
	}

	/***********************************
	 * Initialize, dispose             *
	 ***********************************/
	bool Application::initialize()
	{
		// Load window
		this->mainWindow.create(sf::VideoMode(100, 100), "Hello world!");
		this->mainWindow.setSize(sf::Vector2u(640, 480));
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
	}

	void Application::onResized(sf::Event& e)
	{
		// Update view
		sf::Vector2f center((float)e.size.width / 2, (float)e.size.height / 2);
		sf::Vector2f size((float)e.size.width, (float)e.size.height);
		sf::View view(center, size);

		this->mainWindow.setView(view);
	}


	/***********************************
	 * Renderer                        *
	 ***********************************/
	void Application::onRender(sf::Time& elapsed)
	{
		mainWindow.clear(sf::Color::Black);


		mainWindow.display();
	}

	/***********************************
	 * Game logic                      *
	 ***********************************/
	void Application::onLogicUpdate(sf::Time& elapsed)
	{
		this->fps = (this->fps + (1.0f / elapsed.asSeconds()) ) / 2.0f;
	}


}