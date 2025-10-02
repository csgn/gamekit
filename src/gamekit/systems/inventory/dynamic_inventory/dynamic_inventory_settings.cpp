#include "gamekit/copyright.h"
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_settings.h"

namespace gamekit::systems::inventory::dynamic_inventory
{

bool
DynamicInventorySettings::GetIsExpandable() const
{
	return m_is_expandable;
}

int
DynamicInventorySettings::GetSlotsPerExpansion() const
{
	return m_slots_per_expansion;
}

bool
DynamicInventorySettings::GetIsAutoExpand() const
{
	return m_is_auto_expand;
}

void
DynamicInventorySettings::SetExpandable(bool is_expandable)
{
	m_is_expandable = is_expandable;
}

void
DynamicInventorySettings::SetSlotsPerExpansion(int slots_per_expansion)
{
	m_slots_per_expansion = slots_per_expansion;
}

void
DynamicInventorySettings::SetIsAutoExpand(bool is_auto_expand)
{
	m_is_auto_expand = is_auto_expand;
}

} // namespace gamekit::systems::inventory::dynamic_inventory

