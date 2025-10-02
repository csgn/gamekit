#include <sstream>
#include <string>

#include "gamekit/copyright.h"
#include "gamekit/systems/inventory/dynamic_inventory/dynamic_inventory_slot.h"

namespace gamekit::systems::inventory::dynamic_inventory
{

std::string
DynamicInventorySlot::ToString() const
{

	std::stringstream ss;
	ss << "DynamicInventorySlot(" << this->m_index << ", " << (this->IsEmpty() ? "Empty" : "...") << ")";
	return ss.str();
}

} // namespace gamekit::systems::inventory::dynamic_inventory
