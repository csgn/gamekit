// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/static_inventory/static_inventory_settings.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::static_inventory::StaticInventorySettings;

namespace gamekit_api::systems::inventory::static_inventory
{

GAMEKIT_API StaticInventorySettings* CALL_TYPE
GamekitAPI_StaticInventorySettings_New(int max_capacity, int initial_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_Delete(IInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySettings_GetMaxCapacity(IInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySettings_GetInitialCapacity(IInventorySettings* inventory_settings);

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_SetMaxCapacity(IInventorySettings* inventory_settings, int max_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_SetInitialCapacity(IInventorySettings* inventory_settings, int initial_capacity);

} // namespace gamekit_api::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SETTINGS_API_H
