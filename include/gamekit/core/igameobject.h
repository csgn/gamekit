// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_IGAMEOBJECT_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_IGAMEOBJECT_H

#include "gamekit/copyright.h"

namespace gamekit::core
{

/**
 * @brief Abstract interface representing a basic game object.
 *
 * All objects within the library are expected to implement this interface.
 * Provides a standard way to identify and interact with game objects.
 */
class IGameObject
{
public:
	virtual ~IGameObject() = default;

	/**
	 * @brief Gets the unique identifier of the game object.
	 * @return The unique ID of the object.
	 */
	[[nodiscard]] virtual int GetID() const = 0;
};

} // namespace gamekit::core

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_IGAMEOBJECT_H
