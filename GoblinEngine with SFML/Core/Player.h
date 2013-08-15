#pragma once

#include "Object.h"
#include <SFML\Graphics.hpp>
#include "Build.h"
#include <string>

using sf::Color;

namespace Goblin
{
	class DLLEXPORT Player : public Object
	{
	public:

		enum PlayerKind {
			NeutralPlayer, HumanPlayer, AIPlayer, NetworkPlayer
		};

	private:
		Color color;
		PlayerKind kind;
		std::string name;

	public:
		Player();
		Player(PlayerKind kind, std::string name="Player", Color color=Color());
		virtual ~Player();

		void setColor(Color value);
		void setPlayerKind(PlayerKind value);
		void setName(const std::string& value);

		Color getColor() const;
		PlayerKind getPlayerKind() const;
		std::string getName() const;

		virtual Object* clone() const
		{
			return new Player(*this);
		}
	};

}