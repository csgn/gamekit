#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/static_inventory/static_inventory_settings_api.h"

namespace gamekit_api::systems::inventory::static_inventory
{

GAMEKIT_API StaticInventorySettings* CALL_TYPE
GamekitAPI_StaticInventorySettings_New(const int max_capacity, const int initial_capacity)
{
	return new StaticInventorySettings(max_capacity, initial_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_Delete(IInventorySettings* inventory_settings)
{
	delete inventory_settings;
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySettings_GetMaxCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySettings_GetInitialCapacity(IInventorySettings* inventory_settings)
{
	return inventory_settings->GetInitialCapacity();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_SetMaxCapacity(IInventorySettings* inventory_settings, int max_capacity)
{
	inventory_settings->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_StaticInventorySettings_SetInitialCapacity(IInventorySettings* inventory_settings, int initial_capacity)
{
	inventory_settings->SetInitialCapacity(initial_capacity);
}

} // namespace gamekit_api::systems::inventory::static_inventory
