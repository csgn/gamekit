// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_settings.h"

namespace gamekit::systems::inventory::static_inventory
{
/**
 * @brief Settings for a static (fixed-size) inventory.
 *
 * Inherits from BaseInventorySettings and defines
 * the maximum and initial capacity for a static inventory.
 */
class StaticInventorySettings : public BaseInventorySettings
{
public:
	/**
	 * @brief Constructs StaticInventorySettings with given capacities.
	 * @param max_capacity Maximum number of slots in the inventory.
	 * @param initial_capacity Number of slots at inventory initialization.
	 */
	explicit StaticInventorySettings(const int max_capacity, const int initial_capacity) :
		BaseInventorySettings(max_capacity, initial_capacity)
	{
	}
};

} // namespace gamekit::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H
