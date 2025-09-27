#include "gamekit/copyright.h"
#include "gamekit/gamekit.h"
#include "gamekit/gamekit_api.h"

namespace gamekit::systems::inventory::dynamic_inventory::api
{

GAMEKIT_API DynamicInventorySettings* CALL_TYPE
GamekitAPI_DynamicInventorySettings_New(const int max_capacity, const int initial_capacity, const bool is_expandable,
										const int slots_per_expansion, const bool is_auto_expand)
{
	return new DynamicInventorySettings(max_capacity, initial_capacity, is_expandable, slots_per_expansion,
										is_auto_expand);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_Delete(DynamicInventorySettings* dynamic_inventory_settings)
{
	delete dynamic_inventory_settings;
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetMaxCapacity(DynamicInventorySettings* dynamic_inventory_settings)
{
	return dynamic_inventory_settings->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetInitialCapacity(DynamicInventorySettings* dynamic_inventory_settings)
{
	return dynamic_inventory_settings->GetInitialCapacity();
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsExpandable(DynamicInventorySettings* dynamic_inventory_settings)
{
	return dynamic_inventory_settings->GetIsExpandable();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(DynamicInventorySettings* dynamic_inventory_settings)
{
	return dynamic_inventory_settings->GetSlotsPerExpansion();
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(DynamicInventorySettings* dynamic_inventory_settings)
{
	return dynamic_inventory_settings->GetIsAutoExpand();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetMaxCapacity(DynamicInventorySettings* dynamic_inventory_settings,
												   int max_capacity)
{
	dynamic_inventory_settings->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetInitialCapacity(DynamicInventorySettings* dynamic_inventory_settings,
													   int initial_capacity)
{
	dynamic_inventory_settings->SetInitialCapacity(initial_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetExpandable(DynamicInventorySettings* dynamic_inventory_settings,
												  bool is_expandable)
{
	dynamic_inventory_settings->SetExpandable(is_expandable);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(DynamicInventorySettings* dynamic_inventory_settings,
														 int slots_per_expansion)
{
	dynamic_inventory_settings->SetSlotsPerExpansion(slots_per_expansion);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetAutoExpand(DynamicInventorySettings* dynamic_inventory_settings,
												  bool is_auto_expand)
{
	dynamic_inventory_settings->SetIsAutoExpand(is_auto_expand);
}

} // namespace gamekit::systems::inventory::dynamic_inventory::api
