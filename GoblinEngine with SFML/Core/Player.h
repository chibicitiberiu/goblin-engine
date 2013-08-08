#pragma once

#include "GoblinObject.h"
#include <SFML\Graphics.hpp>
#include "Build.h"

using Color = sf::Color;

namespace Goblin
{
	class DLLEXPORT Player : public GoblinObject
	{
	public:

		enum PlayerKind {
			NeutralPlayer, HumanPlayer, AIPlayer, NetworkPlayer
		};

	private:
		Color color;
		PlayerKind kind;

	public:
		Player(void) { }
		virtual ~Player(void) { }

		void setColor(Color value);
		void setPlayerKind(PlayerKind value);

		Color getColor() const;
		PlayerKind getPlayerKind() const;
	};

}