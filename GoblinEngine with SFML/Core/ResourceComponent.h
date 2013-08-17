#pragma once
#include "component.h"
#include <map>

namespace Goblin
{
	/// <summary>Resource component (e.g. natural resources).</summary>
	class DLLEXPORT ResourceComponent : public Component
	{
	private:
		std::map<int, int>* resources;

	public:
	// Constructor
		/// <summary>Default constructor.</summary>
		ResourceComponent();

		/// <summary>Copy constructor.</summary>
		/// <param name="rc">The resource component.</param>
		ResourceComponent(const ResourceComponent& rc);

		/// <summary>Assignment operator.</summary>
		/// <param name="rc">The resource component.</param>
		/// <returns>A reference to 'this' object.</returns>
		ResourceComponent& operator= (const ResourceComponent& rc);

		/// <summary>Destructor.</summary>
		virtual ~ResourceComponent();

	// Setters
		/// <summary>Sets resource amount.</summary>
		/// <param name="type"> The resource type.</param>
		/// <param name="amount">The resource amount.</param>
		void setResource(int type, int amount);

	// Getters
		/// <summary>Gets resource amount.</summary>
		/// <param name="type">The resource type.</param>
		/// <returns>The resource amount.</returns>
		int getResourceAmount(int type);

	// Object base class
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const;
	};

}