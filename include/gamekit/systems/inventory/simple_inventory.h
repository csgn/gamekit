#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H

#include <memory>
#include <optional>
#include <sstream>

#include "gamekit/systems/inventory/iinventory.h"
#include "gamekit/systems/inventory/iinventory_settings.h"
#include "gamekit/systems/inventory/iinventory_slot.h"

namespace gamekit::systems::inventory
{

class SimpleInventorySettings : public IInventorySettings
{
public:
	explicit SimpleInventorySettings(const int max_capacity, const int initial_capacity) :
		m_max_capacity(max_capacity), m_initial_capacity(initial_capacity)
	{
	}

	const int GetMaxCapacity() const override { return m_max_capacity; }
	const int GetInitialCapacity() const override { return m_initial_capacity; }
	void SetMaxCapacity(int max_capacity) override { m_max_capacity = max_capacity; }
	void SetInitialCapacity(int initial_capacity) override { m_initial_capacity = initial_capacity; }

private:
	int m_max_capacity;
	int m_initial_capacity;
};

template<typename TData>
class SimpleInventorySlot : public IInventorySlot<TData>
{

public:
	explicit SimpleInventorySlot(const int index) : m_index(index) {}

	const int GetIndex() const override { return m_index; }

	TData& GetData() override { return *m_data; }

	const TData& GetData() const override { return *m_data; }

	void SetData(std::unique_ptr<TData> data) override { m_data = std::move(data); }

	bool IsEmpty() const override { return m_data == nullptr; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "SimpleInventorySlot(" << m_index << ", " << (IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}

private:
	int m_index;
	std::unique_ptr<TData> m_data;
};

template<typename TData>
class SimpleInventory : public IInventory<TData, SimpleInventorySettings, SimpleInventorySlot<TData>>
{

public:
	explicit SimpleInventory(std::unique_ptr<SimpleInventorySettings> settings) : m_settings(std::move(settings)) {}

	bool Initialize(std::optional<int> initial_capacity = std::nullopt) override
	{
		int capacity = initial_capacity.value_or(m_settings->GetInitialCapacity());
		m_slots.clear();

		for (int i = 0; i < capacity; i++)
		{
			m_slots.emplace_back(i);
		}

		return true;
	}

	const SimpleInventorySettings& GetSettings() const override { return *m_settings; }

	const std::vector<SimpleInventorySlot<TData>>& GetSlots() const override { return m_slots; }

	std::optional<std::vector<int>> Add(std::unique_ptr<TData> data) override
	{
		const std::optional<int> found_empty_slot_index = FindEmptySlot();
		if (!found_empty_slot_index.has_value())
		{
			// LOG: there is no empty slot found.
			return std::nullopt;
		}

		SimpleInventorySlot<TData>& empty_slot = GetSlot(found_empty_slot_index.value());
		empty_slot.SetData(std::move(data));

		return std::vector{found_empty_slot_index.value()};
	}

	bool Remove(int slot_index) override { return false; }

	std::optional<int> FindEmptySlot() override
	{
		for (SimpleInventorySlot<TData>& slot: m_slots)
		{
			if (slot.IsEmpty())
			{
				return slot.GetIndex();
			}
		}

		return std::nullopt;
	}

	bool HasInventoryEmptySlot() override { return false; }

	bool IsSlotOccupied(int slot_index) override { return false; }

	bool IsInventoryFull() override { return false; }

	SimpleInventorySlot<TData>& GetSlot(int slot_index) override { return m_slots.at(slot_index); }

	const SimpleInventorySlot<TData>& GetSlot(int slot_index) const override { return m_slots.at(slot_index); }

	int GetCapacity() override { return m_slots.size(); }

	int GetOccupiedSlotCount() override
	{
		int occupied_slot_counter = 0;
		for (const SimpleInventorySlot<TData>& slot: m_slots)
		{
			if (!slot.IsEmpty())
				occupied_slot_counter++;
		}

		return occupied_slot_counter;
	}

private:
	std::unique_ptr<SimpleInventorySettings> m_settings;
	std::vector<SimpleInventorySlot<TData>> m_slots;
};


} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
