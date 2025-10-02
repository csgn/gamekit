// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H

#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "gamekit/copyright.h"

#include "gamekit/core/core.h"

#include "gamekit/systems/inventory/iinventory.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_slot.h" // IWYU pragma: export

#include "gamekit/systems/inventory/base_inventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/base_inventory_slot.h" // IWYU pragma: export

namespace gamekit::systems::inventory
{

/**
 * @brief Base template class for an inventory system.
 *
 * Provides standard inventory functionalities such as initialization,
 * adding and removing items, slot queries, and capacity management.
 */
class BaseInventory : public IInventory
{

public:
	/**
	 * @brief Constructs a BaseInventory with given settings.
	 * @param settings Unique pointer to the inventory settings.
	 */
	explicit BaseInventory(std::unique_ptr<IInventorySettings> settings) : m_settings(std::move(settings)) {}

	bool
	Initialize(std::optional<int> initial_capacity) override;

	[[nodiscard]] IInventorySettings&
	GetSettings() override;

	[[nodiscard]] const IInventorySettings&
	GetSettings() const override;

	[[nodiscard]] std::vector<IInventorySlot const*>
	GetSlots() const override;

	std::optional<std::vector<int>>
	Add(std::unique_ptr<core::IKitObject> data) override;

	bool
	Remove(const int slot_index) override;

	[[nodiscard]] std::optional<int>
	FindEmptySlot() const override;

	[[nodiscard]] bool
	HasInventoryEmptySlot() const override;

	[[nodiscard]] bool
	IsSlotOccupied(const int slot_index) const override;

	[[nodiscard]] bool
	IsInventoryFull() const override;

	IInventorySlot&
	GetSlot(int slot_index) override;

	[[nodiscard]] IInventorySlot const&
	GetSlot(int slot_index) const override;

	[[nodiscard]] unsigned long
	GetCapacity() const override;

	[[nodiscard]] int
	GetOccupiedSlotCount() const override;

	[[nodiscard]] bool
	IsSlotIndexInBounds(int slot_index) const override;

private:
	std::unique_ptr<IInventorySettings> m_settings;
	std::vector<std::unique_ptr<IInventorySlot>> m_slots;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
