#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/dynamic_inventory/dynamic_inventory_slot_api.h"

namespace gamekit_api::systems::inventory::dynamic_inventory
{

GAMEKIT_API IInventorySlot* CALL_TYPE
GamekitAPI_DynamicInventorySlot_New(int index)
{
	return new DynamicInventorySlot(index);
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySlot_GetIndex(IInventorySlot* inventory_slot)
{
	return inventory_slot->GetIndex();
}

} // namespace gamekit_api::systems::inventory::dynamic_inventory
