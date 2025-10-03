// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H

#include <memory>
#include <utility>

#include "gamekit/copyright.h"

#include "gamekit/gameplay/inventory/base_inventory.h" // IWYU pragma: export
#include "gamekit/gameplay/inventory/dynamic_inventory/dynamic_inventory_settings.h" // IWYU pragma: export
#include "gamekit/gameplay/inventory/dynamic_inventory/dynamic_inventory_slot.h" // IWYU pragma: export

namespace gamekit::gameplay::inventory::dynamic_inventory
{
/**
 * @brief Dynamic inventory class template.
 *
 * Represents an expandable inventory that can grow over time.
 * Inherits from BaseInventory with DynamicInventorySettings and DynamicInventorySlot.
 *
 */
class DynamicInventory : public BaseInventory
{
public:
	/**
	 * @brief Constructs a DynamicInventory with given settings.
	 * @param settings Unique pointer to DynamicInventorySettings.
	 *
	 */
	explicit DynamicInventory(std::unique_ptr<IInventorySettings> settings) : BaseInventory(std::move(settings)) {}
};

} // namespace gamekit::gameplay::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H
