// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_settings.h"

namespace gamekit::systems::inventory::dynamic_inventory
{
class DynamicInventorySettings : public BaseInventorySettings
{
public:
	explicit DynamicInventorySettings(const int max_capacity, const int initial_capacity, const bool is_expandable,
									  const int slots_per_expansion, const bool is_auto_expand) :
		BaseInventorySettings(max_capacity, initial_capacity),
		m_is_expandable(is_expandable), m_slots_per_expansion(slots_per_expansion), m_is_auto_expand(is_auto_expand)
	{
	}

	[[nodiscard]] bool GetIsExpandable() const { return m_is_expandable; }
	[[nodiscard]] int GetSlotsPerExpansion() const { return m_slots_per_expansion; }
	[[nodiscard]] bool GetIsAutoExpand() const { return m_is_auto_expand; }

	void SetExpandable(bool is_expandable) { m_is_expandable = is_expandable; }
	void SetSlotsPerExpansion(int slots_per_expansion) { m_slots_per_expansion = slots_per_expansion; }
	void SetIsAutoExpand(bool is_auto_expand) { m_is_auto_expand = is_auto_expand; }

protected:
	bool m_is_expandable;
	int m_slots_per_expansion;
	bool m_is_auto_expand;
};

} // namespace gamekit::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SETTINGS_H
