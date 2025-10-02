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

	~BaseInventory() override { std::cout << "BaseInventory destroyed\n"; }

	bool
	Initialize(std::optional<int> initial_capacity) override
	{
		int capacity = initial_capacity.value_or(m_settings->GetInitialCapacity());
		m_slots.clear();

		for (int i = 0; i < capacity; i++)
		{
			m_slots.emplace_back(std::make_unique<BaseInventorySlot>(i));
		}

		return true;
	}

	[[nodiscard]] IInventorySettings&
	GetSettings() override
	{
		return *m_settings;
	}

	[[nodiscard]] const IInventorySettings&
	GetSettings() const override
	{
		return *m_settings;
	}

	[[nodiscard]] std::vector<IInventorySlot const*>
	GetSlots() const override
	{
		std::vector<IInventorySlot const*> slots;
		slots.reserve(m_slots.size());

		for (const auto& slot: m_slots)
		{
			slots.push_back(slot.get());
		}

		return slots;
	}

	std::optional<std::vector<int>>
	Add(std::unique_ptr<core::IKitObject> data) override
	{
		const std::optional<int> found_empty_slot_index = FindEmptySlot();
		if (!found_empty_slot_index.has_value())
		{
			// LOG: there is no empty slot found.
			return std::nullopt;
		}

		IInventorySlot& empty_slot = GetSlot(found_empty_slot_index.value());
		empty_slot.SetData(std::move(data));

		return std::vector{found_empty_slot_index.value()};
	}

	bool
	Remove(const int slot_index) override
	{
		IInventorySlot& slot = GetSlot(slot_index);
		slot.SetData(nullptr);
		return true;
	}

	[[nodiscard]] std::optional<int>
	FindEmptySlot() const override
	{
		for (std::unique_ptr<IInventorySlot> const& slot: m_slots)
		{
			if (slot->IsEmpty())
			{
				return slot->GetIndex();
			}
		}

		return std::nullopt;
	}

	[[nodiscard]] bool
	HasInventoryEmptySlot() const override
	{
		return FindEmptySlot().has_value();
	}

	[[nodiscard]] bool
	IsSlotOccupied(const int slot_index) const override
	{
		return !GetSlot(slot_index).IsEmpty();
	}

	[[nodiscard]] bool
	IsInventoryFull() const override
	{
		return !HasInventoryEmptySlot();
	}

	IInventorySlot&
	GetSlot(int slot_index) override
	{
		assert(IsSlotIndexInBounds(slot_index));
		return *m_slots.at(slot_index);
	}

	[[nodiscard]] IInventorySlot const&
	GetSlot(int slot_index) const override
	{
		assert(IsSlotIndexInBounds(slot_index));
		return *m_slots.at(slot_index);
	}

	[[nodiscard]] unsigned long
	GetCapacity() const override
	{
		return m_slots.size();
	}

	[[nodiscard]] int
	GetOccupiedSlotCount() const override
	{
		int occupied_slot_counter = 0;
		for (const std::unique_ptr<IInventorySlot>& slot: m_slots)
		{
			if (!slot->IsEmpty())
				occupied_slot_counter++;
		}

		return occupied_slot_counter;
	}

	[[nodiscard]] bool
	IsSlotIndexInBounds(int slot_index) const override
	{
		return slot_index >= 0 && slot_index < GetCapacity();
	}

private:
	std::unique_ptr<IInventorySettings> m_settings;
	std::vector<std::unique_ptr<IInventorySlot>> m_slots;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
