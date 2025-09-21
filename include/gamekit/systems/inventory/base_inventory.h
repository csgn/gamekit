// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H

#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "gamekit/systems/inventory/iinventory.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_settings.h" // IWYU pragma: export
#include "gamekit/systems/inventory/iinventory_slot.h" // IWYU pragma: export

namespace gamekit::systems::inventory
{

class BaseInventorySettings : public IInventorySettings
{
public:
	explicit BaseInventorySettings(const int max_capacity, const int initial_capacity) :
		m_max_capacity(max_capacity), m_initial_capacity(initial_capacity)
	{
	}

	[[nodiscard]] int GetMaxCapacity() const override { return m_max_capacity; }
	[[nodiscard]] int GetInitialCapacity() const override { return m_initial_capacity; }
	void SetMaxCapacity(int max_capacity) override { m_max_capacity = max_capacity; }
	void SetInitialCapacity(int initial_capacity) override { m_initial_capacity = initial_capacity; }

protected:
	int m_max_capacity;
	int m_initial_capacity;
};

template<typename TData>
class BaseInventorySlot : public IInventorySlot<TData>
{

public:
	explicit BaseInventorySlot(const int index) : m_index(index) {}

	[[nodiscard]] int GetIndex() const override { return m_index; }

	TData& GetData() override { return *m_data; }

	const TData& GetData() const override { return *m_data; }

	void SetData(std::unique_ptr<TData> data) override { m_data = std::move(data); }

	[[nodiscard]] bool IsEmpty() const override { return m_data == nullptr; }

	[[nodiscard]] std::string ToString() const override
	{
		std::stringstream ss;
		ss << "BaseInventorySlot(" << m_index << ", " << (IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}

protected:
	int m_index;
	std::unique_ptr<TData> m_data;
};

template<typename TData, typename TSettings, typename TSlot>
class BaseInventory : public IInventory<TData, TSettings, TSlot>
{

public:
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

	TSlot& GetSlot(int slot_index) override { return m_slots.at(slot_index); }

	const TSlot& GetSlot(int slot_index) const override { return m_slots.at(slot_index); }

	int GetCapacity() override { return m_slots.size(); }

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

private:
	std::unique_ptr<TSettings> m_settings;
	std::vector<TSlot> m_slots;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_H
