// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/iinventory_settings.h"

namespace gamekit::systems::inventory
{

/**
 * @brief Base configuration settings for an inventory.
 *
 * Implements IInventorySettings and provides basic inventory
 * capacity management (maximum and initial slots).
 */
class BaseInventorySettings : public IInventorySettings
{
public:
	/**
	 * @brief Constructs a BaseInventorySettings instance.
	 *
	 * @param max_capacity Maximum allowed number of slots in the inventory.
	 * @param initial_capacity Number of slots at inventory initialization.
	 */
	explicit BaseInventorySettings(const int max_capacity, const int initial_capacity) :
		m_max_capacity(max_capacity), m_initial_capacity(initial_capacity)
	{
	}

	/**
	 * @brief Returns the maximum allowed inventory capacity.
	 * @return Maximum number of slots.
	 */
	[[nodiscard]] int
	GetMaxCapacity() const override
	{
		return m_max_capacity;
	}

	/**
	 * @brief Returns the initial inventory capacity.
	 * @return Number of slots at initialization.
	 */
	[[nodiscard]] int
	GetInitialCapacity() const override
	{
		return m_initial_capacity;
	}

	/**
	 * @brief Sets the maximum allowed inventory capacity.
	 * @param max_capacity Maximum number of slots.
	 */
	void
	SetMaxCapacity(int max_capacity) override
	{
		m_max_capacity = max_capacity;
	}

	/**
	 * @brief Sets the initial inventory capacity.
	 * @param initial_capacity Number of slots at initialization.
	 */
	void
	SetInitialCapacity(int initial_capacity) override
	{
		m_initial_capacity = initial_capacity;
	}

protected:
	int m_max_capacity; /**< Maximum allowed number of slots in the inventory. */
	int m_initial_capacity; /**< Number of slots at inventory initialization. */
};
} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SETTINGS_H
