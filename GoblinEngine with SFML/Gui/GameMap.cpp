#include "GameMap.h"

namespace Goblin
{
	namespace Gui
	{
		GameMap::GameMap(void)
		{
			this->setUp();
		}


		GameMap::~GameMap(void)
		{
		}

		void GameMap::setUp()
		{
			// Set up map image
			mapImage = sfg::Image::Create();

			// Set up main layout
			mainLayout = sfg::Box::Create(sfg::Box::VERTICAL, 5.0f);
			mainLayout->Pack(mapImage);
			this->setWidget(mainLayout);
		}
	}
}