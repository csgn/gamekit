// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H

#include <sstream>
#include <string>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/base_inventory_slot.h"

namespace gamekit::systems::inventory::static_inventory
{
/**
 * @brief Static inventory slot class template.
 *
 * Represents a single slot in a static (fixed-size) inventory.
 * Inherits from BaseInventorySlot.
 *
 */
class StaticInventorySlot : public BaseInventorySlot
{
public:
	/**
	 * @brief Constructs a StaticInventorySlot with a given index.
	 * @param index The slot's index in the inventory.
	 *
	 */
	explicit StaticInventorySlot(const int index) : BaseInventorySlot(index) {}

	[[nodiscard]] std::string
	ToString() const override
	{
		std::stringstream ss;
		ss << "StaticInventorySlot(" << this->m_index << ", " << (this->IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}
};
} // namespace gamekit::systems::inventory::static_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_STATIC_INVENTORY_STATIC_INVENTORY_SLOT_H
