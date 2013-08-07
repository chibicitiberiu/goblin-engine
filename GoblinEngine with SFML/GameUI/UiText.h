#pragma once
#include "UiTextBase.h"

namespace Goblin
{

	class UiText :
		public UiTextBase
	{
	public:
		UiText(void);
		virtual ~UiText(void);

		virtual bool handleEvent(const sf::Event& e);
	};

}