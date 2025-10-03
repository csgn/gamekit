// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H

#include <sstream>
#include <string>

#include "gamekit/copyright.h"

#include "gamekit/gameplay/inventory/base_inventory_slot.h"

namespace gamekit::gameplay::inventory::dynamic_inventory
{
/**
 * @brief Dynamic inventory slot class template.
 *
 * Represents a single slot in a dynamic (expandable) inventory.
 * Inherits from BaseInventorySlot.
 *
 */
class DynamicInventorySlot : public BaseInventorySlot
{
public:
	/**
	 * @brief Constructs a DynamicInventorySlot with a given index.
	 * @param index The slot's index in the inventory.
	 */
	explicit DynamicInventorySlot(const int index) : BaseInventorySlot(index) {}

	[[nodiscard]] std::string
	ToString() const override;
};
} // namespace gamekit::gameplay::inventory::dynamic_inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_DYNAMIC_INVENTORY_DYNAMIC_INVENTORY_SLOT_H
