// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTION_STATES_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTION_STATES_H

#include "gamekit/copyright.h"

enum class InteractionState
{
    Idle,
    Beginning,
    Interacting,
    Completed,
    Aborted,
    Failed
};

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INTERACTION_INTERACTION_STATES_H
