#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/static_inventory/static_inventory_slot_api.h"

namespace gamekit_api::systems::inventory::static_inventory
{

GAMEKIT_API IInventorySlot* CALL_TYPE
GamekitAPI_StaticInventorySlot_New(int index)
{
	return new StaticInventorySlot(index);
}

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySlot_GetIndex(IInventorySlot* inventory_slot)
{
	return inventory_slot->GetIndex();
}

} // namespace gamekit_api::systems::inventory::static_inventory
