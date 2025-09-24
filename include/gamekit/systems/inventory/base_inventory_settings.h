// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/iinventory_settings.h"

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
} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H
