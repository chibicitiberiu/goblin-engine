#include "../Core/DebugStream.h"
#include "../GameUI/WindowManager.h"
#include "../GameUI/UiBorder.h"
#include "../GameUI/UiText.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 600), "Hello world!");
	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	Goblin::WindowManager wm;

	Goblin::UiBorder* border = new Goblin::UiBorder();
	border->setSize(200, 500);
	border->setForeground(sf::Color(0xff, 0x8f, 0x8f, 0xff));
	border->setBackground(sf::Color::Green);
	border->setAlign(Goblin::UiAlignStretchVert | Goblin::UiAlignLeft);
	border->setZIndex(0);
	wm.getRoot().addChild(border);

	Goblin::UiText* text = new Goblin::UiText();
	text->setFont(arial);
	text->setForeground(sf::Color::Yellow);
	text->setText("Hello world!");
	text->setZIndex(-1);
	text->setAlign(Goblin::UiAlignCenter | Goblin::UiAlign::UiAlignMiddle);
	wm.getRoot().addChild(text);

	Goblin::debug<<"We're in business.\n";

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		wm.render(window);
		window.display();
	}

	Goblin::debug<<"I have something to do...\n";

	return 0;
}
