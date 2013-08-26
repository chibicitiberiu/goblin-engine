#pragma once
#include "../Core/ISceneProvider.h"

/// <summary>Dummy scene provider.</summary>
/// <remarks>Creates and returns a random scene.</remarks>
class DummySceneProvider : public Goblin::ISceneProvider
{
public:
	/// <summary>Destructor.</summary>
	virtual ~DummySceneProvider();

	/// <summary>Gets the scene.</summary>
	/// <returns>The scene.</returns>
	virtual Goblin::SmartPtr<Goblin::Scene> getScene() override;
};

