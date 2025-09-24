// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H

#include <memory>
#include <utility>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory.h" // IWYU pragma: export
#include "gamekit/systems/inventory/static_inventory/static_inventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/static_inventory/static_inventory_slot.h" // IWYU pragma: export

namespace gamekit::systems::inventory::static_inventory
{
template<typename TData>
class StaticInventory : public BaseInventory<TData, StaticInventorySettings, StaticInventorySlot<TData>>
{
public:
	explicit StaticInventory(std::unique_ptr<StaticInventorySettings> settings) : Base(std::move(settings)) {}

private:
	using Base = BaseInventory<TData, StaticInventorySettings, StaticInventorySlot<TData>>;
};

} // namespace gamekit::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_H
