#include <cassert>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h"
#include "gamekit/systems/inventory/base_inventory.h"

namespace gamekit::systems::inventory
{

bool
BaseInventory::Initialize(std::optional<int> initial_capacity)
{
	int capacity = initial_capacity.value_or(m_settings->GetInitialCapacity());
	m_slots.clear();

	for (int i = 0; i < capacity; i++)
	{
		m_slots.emplace_back(std::make_unique<BaseInventorySlot>(i));
	}

	return true;
}

IInventorySettings&
BaseInventory::GetSettings()
{
	return *m_settings;
}

IInventorySettings const&
BaseInventory::GetSettings() const
{
	return *m_settings;
}

std::vector<IInventorySlot const*>
BaseInventory::GetSlots() const
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
BaseInventory::Add(std::unique_ptr<core::IKitObject> data)
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
BaseInventory::Remove(const int slot_index)
{
	IInventorySlot& slot = GetSlot(slot_index);
	slot.SetData(nullptr);
	return true;
}

std::optional<int>
BaseInventory::FindEmptySlot() const
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

bool
BaseInventory::HasInventoryEmptySlot() const
{
	return FindEmptySlot().has_value();
}

bool
BaseInventory::IsSlotOccupied(const int slot_index) const
{
	return !GetSlot(slot_index).IsEmpty();
}

bool
BaseInventory::IsInventoryFull() const
{
	return !HasInventoryEmptySlot();
}

IInventorySlot&
BaseInventory::GetSlot(int slot_index)
{
	assert(IsSlotIndexInBounds(slot_index));
	return *m_slots.at(slot_index);
}

IInventorySlot const&
BaseInventory::GetSlot(int slot_index) const
{
	assert(IsSlotIndexInBounds(slot_index));
	return *m_slots.at(slot_index);
}

unsigned long
BaseInventory::GetCapacity() const
{
	return m_slots.size();
}

int
BaseInventory::GetOccupiedSlotCount() const
{
	int occupied_slot_counter = 0;
	for (const std::unique_ptr<IInventorySlot>& slot: m_slots)
	{
		if (!slot->IsEmpty())
			occupied_slot_counter++;
	}

	return occupied_slot_counter;
}

bool
BaseInventory::IsSlotIndexInBounds(int slot_index) const
{
	return slot_index >= 0 && slot_index < GetCapacity();
}

} // namespace gamekit::systems::inventory
