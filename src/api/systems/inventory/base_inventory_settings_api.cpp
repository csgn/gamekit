#include "gamekit/copyright.h"

#include "gamekit_api/systems/inventory/base_inventory_settings_api.h"

namespace gamekit_api::systems::inventory
{

GAMEKIT_API BaseInventorySettings* CALL_TYPE
GamekitAPI_BaseInventorySettings_New(const int max_capacity, const int initial_capacity)
{
	return new BaseInventorySettings(max_capacity, initial_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_Delete(BaseInventorySettings* base_inventory_settings)
{
	delete base_inventory_settings;
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetMaxCapacity(BaseInventorySettings* base_inventory_settings)
{
	return base_inventory_settings->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetInitialCapacity(BaseInventorySettings* base_inventory_settings)
{
	return base_inventory_settings->GetInitialCapacity();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetMaxCapacity(BaseInventorySettings* base_inventory_settings, int max_capacity)
{
	base_inventory_settings->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetInitialCapacity(BaseInventorySettings* base_inventory_settings,
													int initial_capacity)
{
	base_inventory_settings->SetInitialCapacity(initial_capacity);
}

} // namespace gamekit_api::systems::inventory
