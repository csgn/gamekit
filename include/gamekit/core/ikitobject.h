// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_CORE_IKITOBJECT_H
#define GAMEKIT_INCLUDE_GAMEKIT_CORE_IKITOBJECT_H

#include "gamekit/copyright.h"

namespace gamekit::core
{

/**
 * @brief Abstract interface representing a basic game object.
 *
 * All objects within the library are expected to implement this interface.
 * Provides a standard way to identify and interact with game objects.
 */
class IKitObject
{
public:
	virtual ~IKitObject() = default;

	/**
	 * @brief Gets the unique identifier of the game object.
	 * @return The unique ID of the object.
	 */
	[[nodiscard]] virtual int
	GetID() const = 0;
};

} // namespace gamekit::core

#endif // GAMEKIT_INCLUDE_GAMEKIT_CORE_IKITOBJECT_H
