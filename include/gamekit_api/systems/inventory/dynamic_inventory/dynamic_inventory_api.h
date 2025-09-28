// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H


#include "gamekit/copyright.h"

#include "gamekit/core/igameobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::dynamic_inventory::DynamicInventorySettings;

namespace gamekit_api::systems::inventory::dynamic_inventory
{

GAMEKIT_API DynamicInventorySettings* CALL_TYPE
GamekitAPI_DynamicInventorySettings_New(int max_capacity, int initial_capacity, bool is_expandable,
										int slots_per_expansion, bool is_auto_expand);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_Delete(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetMaxCapacity(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetInitialCapacity(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsExpandable(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(DynamicInventorySettings* dynamic_inventory_settings);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetMaxCapacity(DynamicInventorySettings* dynamic_inventory_settings,
												   int max_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetInitialCapacity(DynamicInventorySettings* dynamic_inventory_settings,
													   int initial_capacity);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetExpandable(DynamicInventorySettings* dynamic_inventory_settings,
												  bool is_expandable);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(DynamicInventorySettings* dynamic_inventory_settings,
														 int slots_per_expansion);

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetAutoExpand(DynamicInventorySettings* dynamic_inventory_settings,
												  bool is_auto_expand);

} // namespace gamekit_api::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_API_H
