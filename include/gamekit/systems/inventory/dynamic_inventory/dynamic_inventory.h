// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H

#include <memory>
#include <utility>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_slot.h" // IWYU pragma: export

namespace gamekit::systems::inventory::dynamic_inventory
{
/**
 * @brief Dynamic inventory class template.
 *
 * Represents an expandable inventory that can grow over time.
 * Inherits from BaseInventory with DynamicInventorySettings and DynamicInventorySlot.
 *
 * @tparam TData Type of data stored in the inventory slots.
 */
template<typename TData>
class DynamicInventory : public BaseInventory<TData, DynamicInventorySettings, DynamicInventorySlot<TData>>
{
public:
	/**
	 * @brief Constructs a DynamicInventory with given settings.
	 * @param settings Unique pointer to DynamicInventorySettings.
	 */
	explicit DynamicInventory(std::unique_ptr<DynamicInventorySettings> settings) : Base(std::move(settings)) {}

private:
	using Base = BaseInventory<TData, DynamicInventorySettings, DynamicInventorySlot<TData>>;
};

} // namespace gamekit::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H
