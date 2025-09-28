// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

namespace gamekit::systems::inventory
{

/**
 * @brief Interface for inventory configuration settings.
 *
 * Provides accessors and mutators for inventory capacities and behaviours.
 */
class IInventorySettings
{
public:
	virtual ~IInventorySettings() = default;

	/**
	 * @brief Gets the maximum allowed inventory capacity.
	 * @return Maximum number of slots.
	 */
	[[nodiscard]] virtual int
	GetMaxCapacity() const = 0;


	/**
	 * @brief Gets the initial inventory capacity.
	 * @return Number of slots at initialization.
	 */
	[[nodiscard]] virtual int
	GetInitialCapacity() const = 0;

	/**
	 * @brief Sets the maximum allowed inventory capacity.
	 * @param max_capacity Maximum number of slots.
	 */
	virtual void
	SetMaxCapacity(int max_capacity) = 0;


	/**
	 * @brief Sets the initial inventory capacity.
	 * @param initial_capacity Number of slots at initialization.
	 */
	virtual void
	SetInitialCapacity(int initial_capacity) = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H
