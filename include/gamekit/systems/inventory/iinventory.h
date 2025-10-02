// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*
//
#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H

#include <memory>
#include <optional>
#include <vector>

#include "gamekit/copyright.h"

#include "gamekit/core/ikitobject.h"
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
 */
class IInventory
{
public:
	virtual ~IInventory() = default;

	/**
	 * @brief Initializes the inventory with optional capacity.
	 * @param initial_capacity Optional initial number of slots.
	 * @return True if initialization was successful.
	 */
	virtual bool
	Initialize(std::optional<int> initial_capacity) = 0;

	/**
	 * @brief Gets the inventory settings.
	 * @return Reference to the settings object.
	 */
	[[nodiscard]] virtual IInventorySettings&
	GetSettings() = 0;

	/**
	 * @brief Gets the inventory settings.
	 * @return Constant reference to the settings object.
	 */
	[[nodiscard]] virtual const IInventorySettings&
	GetSettings() const = 0;

	/**
	 * @brief Gets all inventory slots.
	 * @return Constant reference to vector of slots.
	 */
	[[nodiscard]] virtual std::vector<IInventorySlot*>
	GetSlots() const = 0;

	/**
	 * @brief Adds an item to the inventory.
	 * @param data Unique pointer to the item to add.
	 * @return Optional Vector if item was added successfully, then returns indices of filled slots.
	 */
	virtual std::optional<std::vector<int>>
	Add(std::unique_ptr<core::IKitObject> data) = 0;

	/**
	 * @brief Removes an item from a slot.
	 * @param slot_index Index of the slot to clear.
	 * @return True if removal succeeded.
	 */
	virtual bool
	Remove(int slot_index) = 0;

	/**
	 * @brief Finds an empty slot.
	 * @return Optional index of the first empty slot.
	 */
	virtual std::optional<int>
	FindEmptySlot() = 0;

	/**
	 * @brief Checks if there is at least one empty slot.
	 * @return True if any slot is empty.
	 */
	virtual bool
	HasInventoryEmptySlot() = 0;

	/**
	 * @brief Checks if a slot is occupied.
	 * @param slot_index Index of the slot.
	 * @return True if slot is occupied.
	 */
	virtual bool
	IsSlotOccupied(int slot_index) = 0;

	/**
	 * @brief Checks if the inventory is full.
	 * @return True if no empty slots are available.
	 */
	virtual bool
	IsInventoryFull() = 0;

	/**
	 * @brief Accesses a slot by index.
	 * @param slot_index Index of the slot.
	 * @return Reference to the slot.
	 */
	virtual IInventorySlot&
	GetSlot(int slot_index) = 0;

	/**
	 * @brief Accesses a slot by index (const version).
	 * @param slot_index Index of the slot.
	 * @return Constant reference to the slot.
	 */
	[[nodiscard]] virtual const IInventorySlot&
	GetSlot(int slot_index) const = 0;

	/**
	 * @brief Gets maximum number of slots.
	 * @return Capacity of the inventory.
	 */
	[[nodiscard]] virtual unsigned long
	GetCapacity() const = 0;

	/**
	 * @brief Gets number of occupied slots.
	 * @return Current size of the inventory.
	 */
	virtual int
	GetOccupiedSlotCount() = 0;

	/**
	 * @brief Checks the slot_index is in bounds.
	 * @param slot_index Index of the slot.
	 * @return True if the slot index is in bounds.
	 */
	[[nodiscard]] virtual bool
	IsSlotIndexInBounds(int slot_index) const = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_H
