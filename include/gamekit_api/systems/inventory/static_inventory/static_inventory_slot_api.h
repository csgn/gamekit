// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_API_H

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_slot.h" // IWYU pragma: export
#include "gamekit/systems/inventory/static_inventory/static_inventory_slot.h" // IWYU pragma: export

#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::systems::inventory::IInventorySlot;
using gamekit::systems::inventory::static_inventory::StaticInventorySlot;

namespace gamekit_api::systems::inventory::static_inventory
{

GAMEKIT_API IInventorySlot* CALL_TYPE
GamekitAPI_StaticInventorySlot_New(int index);

GAMEKIT_API int CALL_TYPE
GamekitAPI_StaticInventorySlot_GetIndex(IInventorySlot* inventory_slot);

} // namespace gamekit_api::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_API_H
