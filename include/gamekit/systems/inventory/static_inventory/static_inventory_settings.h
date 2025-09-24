// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_settings.h"

namespace gamekit::systems::inventory::static_inventory
{
class StaticInventorySettings : public BaseInventorySettings
{
public:
	explicit StaticInventorySettings(const int max_capacity, const int initial_capacity) :
		BaseInventorySettings(max_capacity, initial_capacity)
	{
	}
};

} // namespace gamekit::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_H
