#include <memory>

#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/dynamic_inventory/dynamic_inventory_api.h"

namespace gamekit_api::systems::inventory::dynamic_inventory
{

GAMEKIT_API IInventory* CALL_TYPE
GamekitAPI_DynamicInventory_New(IInventorySettings* settings)
{
	return new DynamicInventory(std::unique_ptr<IInventorySettings>(settings));
}

} // namespace gamekit_api::systems::inventory::dynamic_inventory
