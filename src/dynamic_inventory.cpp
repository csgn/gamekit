#include <gamekit/inventory/dynamic_inventory/dynamic_inventory.h>

bool DynamicInventory::Initialize(const std::optional<int> initialCapacity)
{
	return BaseInitialize(initialCapacity);
}

bool DynamicInventory::InitializeSlots(const int initialCapacity)
{
	m_slots = std::vector<DynamicInventorySlot>(initialCapacity);

	for (auto i = 0; i < initialCapacity; ++i)
	{
		m_slots.push_back(DynamicInventorySlot());
	}

	if (m_slots.size() <= 0)
	{
		return false;
	}

	return true;
}

bool DynamicInventory::Add(const IGameObject& data, std::vector<int>& filledSlotIndices)
{
	return false;
}

bool DynamicInventory::Remove(const int slotIndex)
{
	return false;
}

int DynamicInventory::FindEmptySlot()
{
	return 0;
}

bool DynamicInventory::HasInventoryEmptySlot()
{
	return false;
}

bool DynamicInventory::IsSlotOccupied(const int slotIndex)
{
	return false;
}

bool DynamicInventory::IsInventoryFull()
{
	return false;
}
