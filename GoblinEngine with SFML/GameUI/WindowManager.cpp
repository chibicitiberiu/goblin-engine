#include "WindowManager.h"
#include <SFML\Graphics.hpp>

namespace Goblin {

WindowManager::WindowManager()
	: dpi(60)
{
	this->root.setDpi(this->dpi);
}

WindowManager::~WindowManager()
{
}

bool WindowManager::handleEvent(const sf::Event& e)
{
	if (e.type == sf::Event::Resized)
		this->root.setSize((float)e.size.width, (float)e.size.height);

	return this->root.handleEvent(e);
}

void WindowManager::render(sf::RenderTarget& target)
{
	// Sanity check
	if (target.getSize().x == 0 || target.getSize().y == 0)
		return;

	// Temporarily set view
	sf::View oldview = target.getView();
	target.setView(sf::View(sf::FloatRect(0, 0, (float)target.getSize().x, (float)target.getSize().y)));

	// Set data
	root.setActualSize((float)target.getSize().x, (float)target.getSize().y);

	// Render
	root.render(target, sf::FloatRect(0, 0, (float)target.getSize().x, (float)target.getSize().y));

	// Restore view
	target.setView(oldview);
}


UiPanel& WindowManager::getRoot()
{
	return this->root;
}

} // namespace Goblin