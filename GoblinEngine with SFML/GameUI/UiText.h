#pragma once
#include "UiTextBase.h"
#include "../Core/Build.h"

namespace Goblin
{

	class DLLEXPORT UiText :
		public UiTextBase
	{
	public:
		UiText(void);
		virtual ~UiText(void);

		virtual bool handleEvent(const sf::Event& e);
	};

}