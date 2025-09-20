#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H_
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H_

#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

#include "gamekit/core/igameobject.h"
#include "gamekit/systems/inventory/iinventory_settings.h"
#include "gamekit/systems/inventory/iinventory_slot.h"

namespace gamekit::systems::inventory
{

/**
 * @brief Interface for a generic inventory system.
 *
 * Provides core functions to manage an inventory of
 * game objects.
 *
 * @tparam TData Type of inventory data. Must derive from @ref IGameObject.
 * @tparam TSettings Type of inventory settings. Must derive from @ref IInventorySettings.
 * @tparam TSlot Type of inventory slot. Must derive from @ref IInventorySlot<TData>.
 *
 * @see IGameObject
 * @see IInventorySettings
 * @see IInventorySlot
 */
template<typename TData, typename TSettings, typename TSlot>
class IInventory
{
	static_assert(std::is_base_of_v<core::IGameObject, TData>, "TData must derive from InventoryData");
	static_assert(std::is_base_of_v<IInventorySettings, TSettings>, "TSettings must derive from InventorySettings");
	static_assert(std::is_base_of_v<IInventorySlot<TData>, TSlot>, "TSlot must derive from InventorySlot");

public:
	virtual ~IInventory() = default;

	/**
	 * @brief Initializes the inventory with optional capacity.
	 * @param initial_capacity Optional initial number of slots.
	 * @return True if initialization was successful.
	 */
	virtual bool Initialize(std::optional<int> initial_capacity = std::nullopt) = 0;

	/**
	 * @brief Gets the inventory settings.
	 * @return Constant reference to the settings object.
	 */
	virtual const TSettings* GetSettings() const = 0;

	/**
	 * @brief Gets all inventory slots.
	 * @return Constant reference to vector of slots.
	 */
	virtual const std::vector<TSlot>& GetSlots() const = 0;

	/**
	 * @brief Adds an item to the inventory.
	 * @param data Unique pointer to the item to add.
	 * @param filled_slot_indices Vector to store indices of filled slots.
	 * @return True if item was added successfully.
	 */
	virtual bool Add(std::unique_ptr<TData> data, std::vector<int>& filled_slot_indices) = 0;

	/**
	 * @brief Removes an item from a slot.
	 * @param slot_index Index of the slot to clear.
	 * @return True if removal succeeded.
	 */
	virtual bool Remove(int slot_index) = 0;

	/**
	 * @brief Finds an empty slot.
	 * @return Optional index of the first empty slot.
	 */
	virtual std::optional<int> FindEmptySlot() = 0;

	/**
	 * @brief Checks if there is at least one empty slot.
	 * @return True if any slot is empty.
	 */
	virtual bool HasInventoryEmptySlot() = 0;

	/**
	 * @brief Checks if a slot is occupied.
	 * @param slot_index Index of the slot.
	 * @return True if slot is occupied.
	 */
	virtual bool IsSlotOccupied(int slot_index) = 0;

	/**
	 * @brief Checks if the inventory is full.
	 * @return True if no empty slots are available.
	 */
	virtual bool IsInventoryFull() = 0;

	/**
	 * @brief Accesses a slot by index.
	 * @param slot_index Index of the slot.
	 * @return Reference to the slot.
	 */
	virtual TSlot& GetSlot(int slot_index) = 0;

	/**
	 * @brief Accesses a slot by index (const version).
	 * @param slot_index Index of the slot.
	 * @return Constant reference to the slot.
	 */
	virtual const TSlot& GetSlot(int slot_index) const = 0;

	/**
	 * @brief Gets maximum number of slots.
	 * @return Capacity of the inventory.
	 */
	virtual int GetCapacity() = 0;

	/**
	 * @brief Gets number of occupied slots.
	 * @return Current size of the inventory.
	 */
	virtual int GetOccupiedSlotCount() = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H_
