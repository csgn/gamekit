// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H

#include <cstddef>

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h"
#include "gamekit/systems/inventory/iinventory_settings.h"
#include "gamekit/systems/inventory/base_inventory.h"

#include "gamekit_api/gamekit_api_handles.h" // IWYU pragma: export
#include "gamekit_api/gamekit_api_common.h" // IWYU pragma: export

using gamekit::core::IKitObject;
using gamekit::systems::inventory::IInventory;
using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::IInventorySlot;
using gamekit::systems::inventory::BaseInventory;
using gamekit::systems::inventory::BaseInventorySettings;
using gamekit::systems::inventory::BaseInventorySlot;

namespace gamekit_api::systems::inventory
{

GAMEKIT_API HInventory* CALL_TYPE
GamekitAPI_BaseInventory_New(HInventorySettings* h_settings);

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventory_Delete(HInventory* h_inventory);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_Initialize(HInventory* h_inventory, int initial_capacity);

GAMEKIT_API HInventorySettings* CALL_TYPE
GamekitAPI_BaseInventory_GetSettings(HInventory* h_inventory);

GAMEKIT_API HInventorySlot* CALL_TYPE
GamekitAPI_BaseInventory_GetSlots(HInventory* h_inventory, size_t* out_count);

GAMEKIT_API int* CALL_TYPE
GamekitAPI_BaseInventory_Add(HInventory* h_inventory, HKitObject* h_data, size_t* out_indices_count);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_Remove(HInventory* h_inventory, int slot_index);

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventory_FindEmptySlot(HInventory* h_inventory);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_HasInventoryEmptySlot(HInventory* h_inventory);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_IsSlotOccupied(HInventory* h_inventory, int slot_index);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_IsInventoryFull(HInventory* h_inventory);

GAMEKIT_API HInventorySlot* CALL_TYPE
GamekitAPI_BaseInventory_GetSlot(HInventory* h_inventory, int slot_index);

GAMEKIT_API unsigned long CALL_TYPE
GamekitAPI_BaseInventory_GetCapacity(HInventory* h_inventory);

GAMEKIT_API int CALL_TYPE
GamekitAPI_BaseInventory_GetOccupiedSlotCount(HInventory* h_inventory);

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_IsSlotIndexInBounds(HInventory* h_inventory, int slot_index);


} // namespace gamekit_api::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_SYSTEMS_INVENTORY_BASE_INVENTORY_API_H
