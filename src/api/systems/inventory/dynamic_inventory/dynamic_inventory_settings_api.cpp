#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/dynamic_inventory/dynamic_inventory_settings_api.h"

namespace gamekit_api::systems::inventory::dynamic_inventory
{
GAMEKIT_API IInventorySettings* CALL_TYPE
GamekitAPI_DynamicInventorySettings_New(const int max_capacity, const int initial_capacity, const bool is_expandable,
										const int slots_per_expansion, const bool is_auto_expand)
{
	return new DynamicInventorySettings(max_capacity, initial_capacity, is_expandable, slots_per_expansion,
										is_auto_expand);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_Delete(IInventorySettings* inventory_settings)
{
	delete inventory_settings;
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetMaxCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetInitialCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetInitialCapacity();
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsExpandable(IInventorySettings* inventory_settings)
{
	return ((DynamicInventorySettings*) inventory_settings)->GetIsExpandable();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(IInventorySettings* inventory_settings)
{
	return ((DynamicInventorySettings*) inventory_settings)->GetSlotsPerExpansion();
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(IInventorySettings* inventory_settings)
{
	return ((DynamicInventorySettings*) inventory_settings)->GetIsAutoExpand();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetMaxCapacity(IInventorySettings* inventory_settings, int max_capacity)
{
	((DynamicInventorySettings*) inventory_settings)->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetInitialCapacity(IInventorySettings* inventory_settings, int initial_capacity)
{
	((DynamicInventorySettings*) inventory_settings)->SetInitialCapacity(initial_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetExpandable(IInventorySettings* inventory_settings, bool is_expandable)
{
	((DynamicInventorySettings*) inventory_settings)->SetExpandable(is_expandable);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(IInventorySettings* inventory_settings,
														 int slots_per_expansion)
{
	((DynamicInventorySettings*) inventory_settings)->SetSlotsPerExpansion(slots_per_expansion);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_DynamicInventorySettings_SetAutoExpand(IInventorySettings* inventory_settings, bool is_auto_expand)
{
	((DynamicInventorySettings*) inventory_settings)->SetIsAutoExpand(is_auto_expand);
}

} // namespace gamekit_api::systems::inventory::dynamic_inventory
