#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/base_inventory_slot_api.h"

namespace gamekit_api::systems::inventory
{

GAMEKIT_API IInventorySlot* CALL_TYPE
GamekitAPI_BaseInventorySlot_New(int index)
{
	return new BaseInventorySlot(index);
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventorySlot_GetIndex(IInventorySlot* inventory_slot)
{
	return inventory_slot->GetIndex();
}

} // namespace gamekit_api::systems::inventory
