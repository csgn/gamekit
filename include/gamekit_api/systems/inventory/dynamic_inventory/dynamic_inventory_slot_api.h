// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_slot.h" // IWYU pragma: export
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_slot.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventorySlot;
using gamekit::systems::inventory::dynamic_inventory::DynamicInventorySlot;

namespace gamekit_api::systems::inventory::dynamic_inventory
{

GAMEKIT_API IInventorySlot* CALL_TYPE
GamekitAPI_DynamicInventorySlot_New(int index);

GAMEKIT_API int CALL_TYPE
GamekitAPI_DynamicInventorySlot_GetIndex(IInventorySlot* inventory_slot);

} // namespace gamekit_api::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_API_H
