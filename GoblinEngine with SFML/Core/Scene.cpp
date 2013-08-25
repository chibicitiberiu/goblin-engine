#include "Scene.h"

namespace Goblin
{
	Scene::Scene(Vector2u sizeCells, Vector2f sizeAbsolute)
		: _sizeAbsolute(sizeAbsolute),
		  _sizeCells(sizeCells),
		  _players(new PlayersContainer()),
		  _map(new Map(sizeCells.x, sizeCells.y)),
		  _objects(new ObjectContainer()),
		  _objectsPlacement(new ObjectPlacementContainer()),
		  _actionQueue(new ActionQueue())
	{
	}

	Scene::~Scene(void)
	{
		delete _players;
		delete _map;
		delete _objects;
		delete _objectsPlacement;
		delete _actionQueue;
	}

	Vector2f Scene::getSizeAbsolute() const
	{
		return _sizeAbsolute;
	}

	Vector2u Scene::getSizeCells() const
	{
		return _sizeCells;
	}

	Scene::Map& Scene::map()
	{
		return *_map;
	}

	Scene::PlayersContainer& Scene::players()
	{
		return *_players;
	}

	Scene::ObjectContainer& Scene::objects()
	{
		return *_objects;
	}

	Scene::ObjectPlacementContainer& Scene::objectsPlacement()
	{
		return *_objectsPlacement;
	}

	Scene::ActionQueue& Scene::actionQueue()
	{
		return *_actionQueue;
	}

	Vector2f Scene::toAbsolute(Vector2u cell) const
	{
		Vector2f p;
		p.x = static_cast<float>(cell.x) * _sizeAbsolute.x / static_cast<float>(_sizeCells.x);
		p.y = static_cast<float>(cell.y) * _sizeAbsolute.y / static_cast<float>(_sizeCells.y);
		return p;
	}

	Vector2f Scene::toAbsolute(unsigned x, unsigned y) const
	{
		Vector2f p;
		p.x = static_cast<float>(x) * _sizeAbsolute.x / static_cast<float>(_sizeCells.x);
		p.y = static_cast<float>(y) * _sizeAbsolute.y / static_cast<float>(_sizeCells.y);
		return p;
	}

	Vector2u Scene::toCell(Vector2f absolute) const
	{
		Vector2u p;
		p.x = static_cast<unsigned>(absolute.x * static_cast<float>(_sizeCells.x) / _sizeAbsolute.x);
		p.y = static_cast<unsigned>(absolute.y * static_cast<float>(_sizeCells.y) / _sizeAbsolute.y);
		return p;
	}

	Vector2u Scene::toCell(float x, float y) const
	{
		Vector2u p;
		p.x = static_cast<unsigned>(x * static_cast<float>(_sizeCells.x) / _sizeAbsolute.x);
		p.y = static_cast<unsigned>(y * static_cast<float>(_sizeCells.y) / _sizeAbsolute.y);
		return p;
	}
}