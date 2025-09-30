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
GamekitAPI_BaseInventorySettings_Delete(IInventorySettings* inventory_settings)
{
	delete inventory_settings;
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetMaxCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetInitialCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetInitialCapacity();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetMaxCapacity(IInventorySettings* inventory_settings, int max_capacity)
{
	inventory_settings->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetInitialCapacity(IInventorySettings* inventory_settings, int initial_capacity)
{
	inventory_settings->SetInitialCapacity(initial_capacity);
}

} // namespace gamekit_api::systems::inventory
