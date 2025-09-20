#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H

#include <memory>
#include <optional>

#include "gamekit/systems/inventory/iinventory.h"
#include "gamekit/systems/inventory/iinventory_settings.h"
#include "gamekit/systems/inventory/iinventory_slot.h"

class SimpleInventorySettings : public IInventorySettings
{
private:
	int m_max_capacity;
	int m_initial_capacity;

public:
	const int GetMaxCapacity() const override { return m_max_capacity; }
	const int GetInitialCapacity() const override { return m_initial_capacity; }
	void SetMaxCapacity(int max_capacity) override { m_max_capacity = max_capacity; }
	void SetInitialCapacity(int initial_capacity) override { m_initial_capacity = initial_capacity; }
};

template<typename TData>
class SimpleInventorySlot : public IInventorySlot<TData>
{
private:
	int m_index;
	std::unique_ptr<TData> m_data;

public:
	explicit SimpleInventorySlot(int index) : m_index(index) {}

	const int GetIndex() const override { return m_index; }

	TData* GetData() override { return m_data.get(); }

	const TData* GetData() const override { return m_data.get(); }

	void SetData(std::unique_ptr<TData> data) override { m_data = std::move(data); }

	bool IsEmpty() const override { return m_data == nullptr; }

	std::string ToString() const override { return IsEmpty() ? "Empty" : "Occupied"; }
};

template<typename TData>
class SimpleInventory : public IInventory<TData, SimpleInventorySettings, SimpleInventorySlot<TData>>
{
private:
	std::unique_ptr<SimpleInventorySettings> m_settings;
	std::vector<SimpleInventorySlot<TData>> m_slots;

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

	const SimpleInventorySettings* GetSettings() const override { return m_settings.get(); }

	const std::vector<SimpleInventorySlot<TData>>& GetSlots() const override { return m_slots; }

	bool Add(std::unique_ptr<TData> data, std::vector<int>& filledSlotIndices) override { return false; }

	bool Remove(int slot_index) override { return false; }

	std::optional<int> FindEmptySlot() override { return std::nullopt; }

	bool HasInventoryEmptySlot() override { return false; }

	bool IsSlotOccupied(int slot_index) override { return false; }

	bool IsInventoryFull() override { return false; }

	SimpleInventorySlot<TData>& GetSlot(int slot_index) override { return m_slots.at(slot_index); }

	const SimpleInventorySlot<TData>& GetSlot(int slot_index) const override { return m_slots.at(slot_index); }

	int GetCapacity() override { return m_slots.size(); }

	int GetOccupiedSlotCount() override { return 0; }
};

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
