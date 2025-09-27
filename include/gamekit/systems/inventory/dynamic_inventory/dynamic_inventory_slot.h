// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H

#include <sstream>
#include <string>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_slot.h"

namespace gamekit::systems::inventory::dynamic_inventory
{
/**
 * @brief Dynamic inventory slot class template.
 *
 * Represents a single slot in a dynamic (expandable) inventory.
 * Inherits from BaseInventorySlot.
 *
 * @tparam TData Type of data stored in the slot.
 */
template<typename TData>
class DynamicInventorySlot : public BaseInventorySlot<TData>
{
public:
	/**
	 * @brief Constructs a DynamicInventorySlot with a given index.
	 * @param index The slot's index in the inventory.
	 */
	explicit DynamicInventorySlot(const int index) : BaseInventorySlot<TData>(index) {}

	[[nodiscard]] std::string
	ToString() const override
	{
		std::stringstream ss;
		ss << "DynamicInventorySlot(" << this->m_index << ", " << (this->IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}
};
} // namespace gamekit::systems::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H
