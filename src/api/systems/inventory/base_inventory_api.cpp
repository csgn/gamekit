#include <cstddef>
#include <memory>
#include <optional>
#include <vector>

#include "gamekit/copyright.h"
#include "gamekit_api/systems/inventory/base_inventory_api.h"

namespace gamekit_api::systems::inventory
{

GAMEKIT_API HInventory* CALL_TYPE
GamekitAPI_BaseInventory_New(HInventorySettings* h_settings)
{
	return reinterpret_cast<HInventory*>(
			new BaseInventory(std::unique_ptr<IInventorySettings>(reinterpret_cast<IInventorySettings*>(h_settings))));
}

GAMEKIT_API void CALL_TYPE
GamekitAPI_BaseInventory_Delete(HInventory* h_inventory)
{
	delete reinterpret_cast<IInventory*>(h_inventory);
}

GAMEKIT_API HInventorySettings* CALL_TYPE
GamekitAPI_BaseInventory_GetSettings(HInventory* h_inventory)
{
	return reinterpret_cast<HInventorySettings*>(&reinterpret_cast<IInventory*>(h_inventory)->GetSettings());
}

GAMEKIT_API bool CALL_TYPE
GamekitAPI_BaseInventory_Initialize(HInventory* h_inventory, int initial_capacity)
{
	return reinterpret_cast<IInventory*>(h_inventory)
			->Initialize(initial_capacity > 0 ? std::optional<int>(initial_capacity) : std::nullopt);
}

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
