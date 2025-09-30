// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/base_inventory.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventory;
using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::BaseInventory;

namespace gamekit_api::systems::inventory
{

GAMEKIT_API IInventory* CALL_TYPE
GamekitAPI_BaseInventory_New(IInventorySettings* settings);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_Initialize(IInventory* inventory, int initial_capacity);

GAMEKIT_API const IInventorySettings* CALL_TYPE
GamekitAPI_BaseInventory_GetSettings(IInventory* inventory);

} // namespace gamekit_api::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H
