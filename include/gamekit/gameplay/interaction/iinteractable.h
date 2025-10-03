// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTABLE_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTABLE_H

#include "gamekit/copyright.h"
#include "gamekit/core/ec/ibehaviour.h" // IWYU pragma: export
#include "gamekit/gameplay/interaction/interaction_states.h" // IWYU pragma: export
#include "gamekit/gameplay/interaction/interaction_types.h" // IWYU pragma: export

using gamekit::core::ec::IBehaviour;

namespace gamekit::gameplay::interaction
{

class IInteractor;

class IInteractable : public IBehaviour
{
public:
	virtual void
	Interact(IInteractor& interactor) = 0;
};

} // namespace gamekit::gameplay::interaction

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTABLE_H
