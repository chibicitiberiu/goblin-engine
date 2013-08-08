#pragma once
#include "UiElement.h"
#include "../Core/Build.h"
#include <vector>

namespace Goblin {

	class DLLEXPORT UiContainer: public UiElement {

	public:
		typedef std::vector<UiElement*> ChildrenVector;
		typedef ChildrenVector::iterator ChildrenIterator;

	private:
		ChildrenVector children;

	public:
		UiContainer();
		virtual ~UiContainer();

		// Children getters
		virtual ChildrenIterator childrenBegin();
		virtual ChildrenIterator childrenEnd();
		virtual size_t childrenCount();
		virtual UiElement* child(size_t index);

		// Children modifiers
		virtual void addChild(UiElement* el);
		virtual void removeChild(ChildrenIterator it);
		virtual void removeChild(size_t index);

	protected:

		// Events
		virtual void onLayoutChanged();
		virtual void onAppearanceChanged();
		virtual void onEnabledChanged();
	};

}  // namespace Goblin