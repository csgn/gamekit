#ifndef GAMEKIT_DYNAMIC_INVENTORY_SETTINGS_H
#define GAMEKIT_DYNAMIC_INVENTORY_SETTINGS_H
#pragma once

#include <stdexcept>

#include "gamekit/inventory/iinventory_settings.h"

class DynamicInventorySettings final : public IInventorySettings
{
protected:
	int m_max_capacity;
	int m_initial_capacity;
	bool m_is_expandable;
	int m_slots_per_expansion;
	bool m_has_auto_expand;

public:
	DynamicInventorySettings(const int max_capacity, const int initial_capacity,
							 const std::optional<bool> is_expandable = std::nullopt,
							 const std::optional<int> slots_per_expansion = std::nullopt,
							 const std::optional<bool> has_auto_expand = std::nullopt)
	{
		if (max_capacity <= 0)
			throw std::invalid_argument("max_capacity must be greater than zero");
		if (initial_capacity <= 0)
			throw std::invalid_argument("initial_capacity must be greater than zero");
		if (initial_capacity > max_capacity)
			throw std::invalid_argument("max_capacity exceeded");

		if (slots_per_expansion.has_value())
		{
			if (slots_per_expansion.value() > max_capacity)
				throw std::invalid_argument("slots_per_expansion exceeded");
		}

		m_max_capacity = max_capacity;
		m_initial_capacity = initial_capacity;
		m_is_expandable = is_expandable.value_or(false);
		m_slots_per_expansion = slots_per_expansion.value_or(1);
		m_has_auto_expand = has_auto_expand.value_or(false);
	}

	const int GetMaxCapacity() const override { return m_max_capacity; }

	const int GetInitialCapacity() const override { return m_initial_capacity; }

	bool IsExpandable() const { return m_is_expandable; }

	int GetSlotsPerExpansion() const { return m_slots_per_expansion; }

	bool HasAutoExpand() const { return m_has_auto_expand; }

	void SetMaxCapacity(const int max_capacity) override { m_max_capacity = max_capacity; }

	void SetInitialCapacity(const int initial_capacity) override { m_initial_capacity = initial_capacity; }

	void SetExpandable(const bool value) { m_is_expandable = value; }

	void SetSlotsPerExpansion(const int value) { m_slots_per_expansion = value; }

	void SetHasAutoExpand(const bool value) { m_has_auto_expand = value; }
};

#endif // GAMEKIT_DYNAMIC_INVENTORY_SETTINGS_H
