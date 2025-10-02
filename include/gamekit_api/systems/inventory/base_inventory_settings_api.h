// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/base_inventory_settings.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_handles.h" // IYWU pragma: export
#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::BaseInventorySettings;

namespace gamekit_api::systems::inventory
{

GAMEKIT_API HInventorySettings* CALL_TYPE
GamekitAPI_BaseInventorySettings_New(int max_capacity, int initial_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_Delete(HInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetMaxCapacity(HInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetInitialCapacity(HInventorySettings* inventory_settings);

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetMaxCapacity(HInventorySettings* inventory_settings, int max_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetInitialCapacity(HInventorySettings* inventory_settings, int initial_capacity);

} // namespace gamekit_api::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_API_H
