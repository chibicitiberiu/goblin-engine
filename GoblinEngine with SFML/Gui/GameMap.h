#pragma once
#include "Widget.h"

namespace Goblin
{
	namespace Gui
	{
		class GameMap : public Widget
		{
		public:
			enum MapPlot {
				Terrain = 0x1,
				Height = 0x2,
				Players = 0x4,
				Resources = 0x8
			};

		private:
			sfg::Box::Ptr mainLayout;
			sfg::Image::Ptr mapImage;

			void setUp();

		public:
			GameMap(void);
			virtual ~GameMap(void);
		};

	}
}