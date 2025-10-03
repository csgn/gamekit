// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H

#include <memory>
#include <utility>

#include "gamekit/copyright.h"

#include "gamekit/gameplay/inventory/base_inventory.h" // IWYU pragma: export
#include "gamekit/gameplay/inventory/static_inventory/static_inventory_settings.h" // IWYU pragma: export
#include "gamekit/gameplay/inventory/static_inventory/static_inventory_slot.h" // IWYU pragma: export

namespace gamekit::gameplay::inventory::static_inventory
{
/**
 * @brief Static inventory class template.
 *
 * Represents a fixed-size inventory that cannot expand.
 * Inherits from BaseInventory with StaticInventorySettings and StaticInventorySlot.
 *
 */
class StaticInventory : public BaseInventory
{
public:
	/**
	 * @brief Constructs a StaticInventory with given settings.
	 * @param settings Unique pointer to StaticInventorySettings.
	 *
	 */
	explicit StaticInventory(std::unique_ptr<IInventorySettings> settings) : BaseInventory(std::move(settings)) {}
};

} // namespace gamekit::gameplay::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H
