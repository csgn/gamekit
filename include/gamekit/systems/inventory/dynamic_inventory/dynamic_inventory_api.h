// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H

#include "gamekit/copyright.h"

#include "gamekit/core/igameobject.h" // IWYU pragma: export
#include "gamekit/gamekit_api_common.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory.h" // IWYU pragma: export

namespace gamekit::systems::inventory::dynamic_inventory::api
{

GAMEKIT_API DynamicInventorySettings* CALL_TYPE GamekitAPI_DynamicInventorySettings_New(
		int max_capacity, int initial_capacity, bool is_expandable, int slots_per_expansion, bool is_auto_expand);

} // namespace gamekit::systems::inventory::dynamic_inventory::api

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H
