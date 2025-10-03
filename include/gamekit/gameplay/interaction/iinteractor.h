// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTOR_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTOR_H

#include "gamekit/copyright.h"
#include "gamekit/core/ec/ientity.h" // IWYU pragma: export
#include "gamekit/core/ec/ibehaviour.h" // IWYU pragma: export
#include "gamekit/gameplay/interaction/interaction_states.h" // IWYU pragma: export
#include "gamekit/gameplay/interaction/interaction_types.h" // IWYU pragma: export

using namespace gamekit::core::ec;

namespace gamekit::gameplay::interaction
{

class IInteractable;

class IInteractor : public IBehaviour
{
public:
	virtual void
	InteractWith(IInteractable& target) = 0;

	template<typename T>
	void
	InteractWith(IEntity& target)
	{
		static_assert(std::is_base_of_v<IInteractable, T>, "T must derive from IInteractable");
		if (auto* behaviour = target.GetBehaviour<T>())
			InteractWith(*behaviour);
	}

	virtual void
	InteractionCallback(IInteractable& target) = 0;
};

} // namespace gamekit::gameplay::interaction

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTOR_H
