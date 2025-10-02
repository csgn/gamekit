#include "gamekit/copyright.h"

#include "gamekit_api/gamekit_api_handles.h"
#include "gamekit_api/systems/inventory/base_inventory_settings_api.h"

namespace gamekit_api::systems::inventory
{

GAMEKIT_API HInventorySettings* CALL_TYPE
GamekitAPI_BaseInventorySettings_New(const int max_capacity, const int initial_capacity)
{
	return reinterpret_cast<HInventorySettings*>(new BaseInventorySettings(max_capacity, initial_capacity));
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_Delete(HInventorySettings* inventory_settings)
{
	delete reinterpret_cast<IInventorySettings*>(inventory_settings);
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetMaxCapacity(HInventorySettings* inventory_settings)
{
	return reinterpret_cast<IInventorySettings*>(inventory_settings)->GetMaxCapacity();
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySettings_GetInitialCapacity(HInventorySettings* inventory_settings)
{
	return reinterpret_cast<IInventorySettings*>(inventory_settings)->GetInitialCapacity();
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetMaxCapacity(HInventorySettings* inventory_settings, int max_capacity)
{
	return reinterpret_cast<IInventorySettings*>(inventory_settings)->SetMaxCapacity(max_capacity);
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventorySettings_SetInitialCapacity(HInventorySettings* inventory_settings, int initial_capacity)
{
	return reinterpret_cast<IInventorySettings*>(inventory_settings)->SetInitialCapacity(initial_capacity);
}

} // namespace gamekit_api::systems::inventory
