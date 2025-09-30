// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_settings.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::dynamic_inventory::DynamicInventorySettings;

namespace gamekit_api::systems::inventory::dynamic_inventory
{

GAMEKIT_API IInventorySettings* CALL_TYPE
GamekitAPI_DynamicInventorySettings_New(int max_capacity, int initial_capacity, bool is_expandable,
										int slots_per_expansion, bool is_auto_expand);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_Delete(IInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetMaxCapacity(IInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetInitialCapacity(IInventorySettings* inventory_settings);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsExpandable(IInventorySettings* inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(IInventorySettings* inventory_settings);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(IInventorySettings* inventory_settings);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetMaxCapacity(IInventorySettings* inventory_settings, int max_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetInitialCapacity(IInventorySettings* inventory_settings, int initial_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetExpandable(IInventorySettings* inventory_settings, bool is_expandable);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(IInventorySettings* inventory_settings,
														 int slots_per_expansion);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetAutoExpand(IInventorySettings* inventory_settings, bool is_auto_expand);

} // namespace gamekit_api::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_API_H
