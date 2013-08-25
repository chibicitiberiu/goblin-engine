#pragma once
#include "../Core/MapCell.h"
#include "../Core/Scene.h"
#include "../Core/ISceneProvider.h"

using sf::FloatRect;

namespace Goblin
{
	class DLLEXPORT GameController : public Object
	{
	private:

		SmartPtr<Scene> _scene;
		
	public:
	
	// Constructor, destructor
		/// <summary>Constructor.</summary>
		/// <param name="sceneProvider">The scene provider.</param>
		GameController(ISceneProvider& sceneProvider);

		/// <summary>Destructor.</summary>
		virtual ~GameController(void);


	// Scene
		/// <summary>Gets the scene.</summary>
		/// <returns>The scene.</returns>
		virtual Scene& scene();

	// Players
		/// <summary>Adds a player.</summary>
		/// <param name="name">The player's name.</param>
		/// <param name="color">The player's color.</param>
		/// <returns>The player's identification number.</returns>
		virtual Player::PlayerId addPlayer(std::string name, Color color);

/* TODO:
		// Actions
		virtual void addAction(SmartPtr<GameObject> object, SmartPtr<Action> action);

		// Interactions
		virtual void select(Player::PlayerId, bool add_to_selection, FloatRect area_absolute);
		virtual void move(Player::PlayerId, Vector2f dest);

		// Tick
		virtual void actionsTick(const sf::Time& elapsed);
		virtual void tick(const sf::Time& elapsed); */

		// Object
		virtual Object* clone() const;
	};

}