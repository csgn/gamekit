#include <memory>

#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/static_inventory/static_inventory_api.h"

namespace gamekit_api::systems::inventory::static_inventory
{

GAMEKIT_API IInventory* CALL_TYPE
GamekitAPI_StaticInventory_New(IInventorySettings* settings)
{
	return new StaticInventory(std::unique_ptr<IInventorySettings>(settings));
}

} // namespace gamekit_api::systems::inventory::static_inventory
