#include "gamekit/copyright.h"
#include "gamekit/gameplay/inventory/base_inventory_settings.h"

namespace gamekit::gameplay::inventory
{

int
BaseInventorySettings::GetMaxCapacity() const
{
	return m_max_capacity;
}

int
BaseInventorySettings::GetInitialCapacity() const
{
	return m_initial_capacity;
}

void
BaseInventorySettings::SetMaxCapacity(int max_capacity)
{
	m_max_capacity = max_capacity;
}

void
BaseInventorySettings::SetInitialCapacity(int initial_capacity)
{
	m_initial_capacity = initial_capacity;
}

} // namespace gamekit::gameplay::inventory

