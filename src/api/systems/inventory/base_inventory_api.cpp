#include <memory>

#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/base_inventory_api.h"

namespace gamekit_api::systems::inventory
{

GAMEKIT_API IInventory* CALL_TYPE
GamekitAPI_BaseInventory_New(IInventorySettings* settings)
{
	return new BaseInventory(std::unique_ptr<IInventorySettings>(settings));
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_Initialize(IInventory* inventory, int initial_capacity)
{
	return inventory->Initialize(initial_capacity);
}

GAMEKIT_API const IInventorySettings* CALL_TYPE
GamekitAPI_BaseInventory_GetSettings(IInventory* inventory)
{
	return &inventory->GetSettings();
}

} // namespace gamekit_api::systems::inventory
