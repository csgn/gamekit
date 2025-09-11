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
	DynamicInventorySettings& m_settings;
	std::vector<std::reference_wrapper<DynamicInventorySlot>> m_slots;

public:
	explicit DynamicInventory(DynamicInventorySettings& settings) : m_settings(settings) {}

	const DynamicInventorySettings& GetSettings() const override { return m_settings; }

	bool Initialize(const std::optional<int> initialCapacity = std::nullopt) override
	{
		return Initialize_(initialCapacity);
	}

	const std::vector<std::reference_wrapper<DynamicInventorySlot>> GetSlots() const override { return m_slots; }

	int Add(IGameObject& data) override { return Add_(data); }
};

#endif // DYNAMIC_INVENTORY_H
