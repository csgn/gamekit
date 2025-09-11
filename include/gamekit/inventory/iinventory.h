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
	bool Initialize_(std::optional<int> initialCapacity = std::nullopt)
	{
		auto& settings = GetSettings();
		const int decidedInitialCapacity = initialCapacity.value_or(settings.GetInitialCapacity());
		const int maxCapacity = settings.GetMaxCapacity();

		if (decidedInitialCapacity > maxCapacity)
		{
			// max capacity reached
			return false;
		}

		// inventory initialized
		return true;
	}

	int Add_(const TData& data) { return -1; }

public:
	virtual ~IInventory() = default;

	virtual bool Initialize(std::optional<int> initialCapacity = std::nullopt) = 0;

	virtual const TSettings& GetSettings() const = 0;

	virtual const std::vector<std::reference_wrapper<TSlot>> GetSlots() const = 0;

	virtual int Add(TData& data) = 0;
};


#endif // IINVENTORY_H
