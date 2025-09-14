#ifndef IINVENTORY_H
#define IINVENTORY_H
#pragma once

#include <optional>
#include <type_traits>
#include <vector>

#include "gamekit/igameobject.h"

#include "iinventory_settings.h"
#include "iinventory_slot.h"

template<typename TData, typename TSettings, typename TSlot>
class IInventory
{
	static_assert(std::is_base_of_v<IGameObject, TData>, "TData must derive from InventoryData");
	static_assert(std::is_base_of_v<IInventorySettings, TSettings>, "TSettings must derive from InventorySettings");
	static_assert(std::is_base_of_v<IInventorySlot<TData>, TSlot>, "TSlot must derive from InventorySlot");

protected:
	bool BaseInitialize(std::optional<int> initialCapacity = std::nullopt)
	{
		auto& settings = GetSettings();
		const int decidedInitialCapacity = initialCapacity.value_or(settings.GetInitialCapacity());
		const int maxCapacity = settings.GetMaxCapacity();

		if (decidedInitialCapacity > maxCapacity)
		{
			// max capacity reached
			return false;
		}

		InitializeSlots(decidedInitialCapacity);

		// inventory initialized
		return true;
	}

protected:
	virtual bool InitializeSlots(int initialCapacity) = 0;

public:
	virtual ~IInventory() = default;

	virtual bool Initialize(std::optional<int> initialCapacity = std::nullopt) = 0;

	virtual const TSettings& GetSettings() const = 0;

	virtual const std::vector<TSlot>& GetSlots() const = 0;

	virtual bool Add(const TData& data, std::vector<int>& filledSlotIndices) = 0;

	virtual bool Remove(int slotIndex) = 0;

	virtual int FindEmptySlot() = 0;

	virtual bool HasInventoryEmptySlot() = 0;

	virtual bool IsSlotOccupied(int slotIndex) = 0;

	virtual bool IsInventoryFull() = 0;
};

#endif // IINVENTORY_H
