// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H

#include <cassert>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "gamekit/copyright.h"

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
 *
 * @tparam TData Type of data stored in each inventory slot.
 * @tparam TSettings Type of inventory settings class (must inherit from IInventorySettings).
 * @tparam TSlot Type of inventory slot class (must implement IInventorySlot<TData> interface).
 */
template<typename TData, typename TSettings, typename TSlot>
class BaseInventory : public IInventory<TData, TSettings, TSlot>
{

public:
	/**
	 * @brief Constructs a BaseInventory with given settings.
	 * @param settings Unique pointer to the inventory settings.
	 */
	explicit BaseInventory(std::unique_ptr<TSettings> settings) : m_settings(std::move(settings)) {}

	bool Initialize(std::optional<int> initial_capacity) override
	{
		int capacity = initial_capacity.value_or(m_settings->GetInitialCapacity());
		m_slots.clear();

		for (int i = 0; i < capacity; i++)
		{
			m_slots.emplace_back(i);
		}

		return true;
	}

	[[nodiscard]] const TSettings& GetSettings() const override { return *m_settings; }

	const std::vector<TSlot>& GetSlots() const override { return m_slots; }

	std::optional<std::vector<int>> Add(std::unique_ptr<TData> data) override
	{
		const std::optional<int> found_empty_slot_index = FindEmptySlot();
		if (!found_empty_slot_index.has_value())
		{
			// LOG: there is no empty slot found.
			return std::nullopt;
		}

		TSlot& empty_slot = GetSlot(found_empty_slot_index.value());
		empty_slot.SetData(std::move(data));

		return std::vector{found_empty_slot_index.value()};
	}

	bool Remove(const int slot_index) override
	{
		TSlot& slot = GetSlot(slot_index);
		slot.SetData(nullptr);
		return true;
	}

	std::optional<int> FindEmptySlot() override
	{
		for (TSlot& slot: m_slots)
		{
			if (slot.IsEmpty())
			{
				return slot.GetIndex();
			}
		}

		return std::nullopt;
	}

	bool HasInventoryEmptySlot() override { return FindEmptySlot().has_value(); }

	bool IsSlotOccupied(const int slot_index) override { return !GetSlot(slot_index).IsEmpty(); }

	bool IsInventoryFull() override { return !HasInventoryEmptySlot(); }

	TSlot& GetSlot(int slot_index) override
	{
		assert(IsSlotIndexInBounds(slot_index));
		return m_slots.at(slot_index);
	}

	const TSlot& GetSlot(int slot_index) const override
	{
		assert(IsSlotIndexInBounds(slot_index));
		return m_slots.at(slot_index);
	}

	[[nodiscard]] int GetCapacity() const override { return m_slots.size(); }

	int GetOccupiedSlotCount() override
	{
		int occupied_slot_counter = 0;
		for (const TSlot& slot: m_slots)
		{
			if (!slot.IsEmpty())
				occupied_slot_counter++;
		}

		return occupied_slot_counter;
	}

	[[nodiscard]] bool IsSlotIndexInBounds(int slot_index) const override
	{
		return slot_index >= 0 && slot_index < GetCapacity();
	}

private:
	std::unique_ptr<TSettings> m_settings;
	std::vector<TSlot> m_slots;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
