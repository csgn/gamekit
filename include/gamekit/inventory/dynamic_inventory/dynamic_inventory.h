#ifndef DYNAMIC_INVENTORY_H
#define DYNAMIC_INVENTORY_H
#pragma once

#include <vector>

#include "gamekit/inventory/iinventory.h"

#include "dynamic_inventory_settings.h"
#include "dynamic_inventory_slot.h"

class DynamicInventory final : public IInventory<IGameObject, DynamicInventorySettings, DynamicInventorySlot>
{
private:
	DynamicInventorySettings m_settings;
	std::vector<DynamicInventorySlot> m_slots;

protected:
	bool InitializeSlots(int initialCapacity) override;

public:
	explicit DynamicInventory(DynamicInventorySettings settings) : m_settings(settings) {}

	bool Initialize(std::optional<int> initialCapacity = std::nullopt) override;

	const DynamicInventorySettings& GetSettings() const override { return m_settings; }

	const std::vector<DynamicInventorySlot>& GetSlots() const override { return m_slots; }

	bool Add(const IGameObject& data, std::vector<int>& filledSlotIndices) override;

	bool Remove(int slotIndex) override;

	int FindEmptySlot() override;

	bool HasInventoryEmptySlot() override;

	bool IsSlotOccupied(int slotIndex) override;

	bool IsInventoryFull() override;
};

#endif // DYNAMIC_INVENTORY_H
