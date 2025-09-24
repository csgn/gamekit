// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H

#include <sstream>
#include <string>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_slot.h"

namespace gamekit::systems::inventory::static_inventory
{
template<typename TData>
class StaticInventorySlot : public BaseInventorySlot<TData>
{
public:
	explicit StaticInventorySlot(const int index) : BaseInventorySlot<TData>(index) {}

	[[nodiscard]] std::string ToString() const override
	{
		std::stringstream ss;
		ss << "StaticInventorySlot(" << this->m_index << ", " << (this->IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}
};
} // namespace gamekit::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H
