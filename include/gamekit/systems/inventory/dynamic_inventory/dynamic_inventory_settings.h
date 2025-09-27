// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_settings.h"

namespace gamekit::systems::inventory::dynamic_inventory
{

/**
 * @brief Configuration settings for a dynamic inventory.
 *
 * Extends BaseInventorySettings to support inventories that can expand
 * over time. Provides settings for expandability, slots per expansion,
 * and automatic expansion behavior.
 */
class DynamicInventorySettings : public BaseInventorySettings
{
public:
	/**
	 * @brief Constructs a DynamicInventorySettings instance.
	 *
	 * @param max_capacity Maximum allowed number of slots.
	 * @param initial_capacity Initial number of slots at inventory creation.
	 * @param is_expandable Whether the inventory can expand beyond the initial capacity.
	 * @param slots_per_expansion Number of slots to add on each expansion.
	 * @param is_auto_expand Whether the inventory should expand automatically when full.
	 */
	explicit DynamicInventorySettings(const int max_capacity, const int initial_capacity, const bool is_expandable,
									  const int slots_per_expansion, const bool is_auto_expand) :
		BaseInventorySettings(max_capacity, initial_capacity),
		m_is_expandable(is_expandable), m_slots_per_expansion(slots_per_expansion), m_is_auto_expand(is_auto_expand)
	{
	}

	/**
	 * @brief Returns whether the inventory is expandable.
	 * @return True if the inventory can expand, false otherwise.
	 */
	[[nodiscard]] bool
	GetIsExpandable() const
	{
		return m_is_expandable;
	}

	/**
	 * @brief Returns the number of slots added on each expansion.
	 * @return Number of slots per expansion.
	 */
	[[nodiscard]] int
	GetSlotsPerExpansion() const
	{
		return m_slots_per_expansion;
	}

	/**
	 * @brief Returns whether the inventory auto-expands when full.
	 * @return True if auto-expansion is enabled, false otherwise.
	 */
	[[nodiscard]] bool
	GetIsAutoExpand() const
	{
		return m_is_auto_expand;
	}

	/**
	 * @brief Sets whether the inventory is expandable.
	 * @param is_expandable True to make inventory expandable, false otherwise.
	 */
	void
	SetExpandable(bool is_expandable)
	{
		m_is_expandable = is_expandable;
	}

	/**
	 * @brief Sets the number of slots to add on each expansion.
	 * @param slots_per_expansion Number of slots to add per expansion.
	 */
	void
	SetSlotsPerExpansion(int slots_per_expansion)
	{
		m_slots_per_expansion = slots_per_expansion;
	}

	/**
	 * @brief Sets whether the inventory should auto-expand when full.
	 * @param is_auto_expand True to enable auto-expansion, false to disable.
	 */
	void
	SetIsAutoExpand(bool is_auto_expand)
	{
		m_is_auto_expand = is_auto_expand;
	}

protected:
	bool m_is_expandable; /**< Whether the inventory can expand. */
	int m_slots_per_expansion; /**< Number of slots added per expansion. */
	bool m_is_auto_expand; /**< Whether the inventory auto-expands when full. */
};

} // namespace gamekit::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H
