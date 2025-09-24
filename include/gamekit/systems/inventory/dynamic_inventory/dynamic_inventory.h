// IWYU pragma: private, include "gamekit/gamekit.h"

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
template<typename TData>
class DynamicInventory : public BaseInventory<TData, DynamicInventorySettings, DynamicInventorySlot<TData>>
{
public:
	explicit DynamicInventory(std::unique_ptr<DynamicInventorySettings> settings) : Base(std::move(settings)) {}

private:
	using Base = BaseInventory<TData, DynamicInventorySettings, DynamicInventorySlot<TData>>;
};

} // namespace gamekit::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_H
