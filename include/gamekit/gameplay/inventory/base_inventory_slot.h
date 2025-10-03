// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_BASE_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_BASE_INVENTORY_SLOT_H

#include <memory>
#include <sstream>
#include <string>
#include <utility>

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h"
#include "gamekit/gameplay/inventory/iinventory_slot.h"

namespace gamekit::gameplay::inventory
{

/**
 * @brief Base inventory slot class template.
 *
 * Represents a single slot in an inventory. Each slot has an index and can
 * hold data of type IKitObject. Provides basic slot functionalities such as
 * checking if the slot is empty and setting/getting the stored data.
 *
 */
class BaseInventorySlot : public IInventorySlot
{

public:
	/**
	 * @brief Base inventory slot class template.
	 *
	 * Represents a single slot in an inventory. Each slot has an index and can
	 * hold data of type IKitObject.
	 *
	 */
	explicit BaseInventorySlot(const int index) : m_index(index) {}

	[[nodiscard]] int
	GetIndex() const override;

	core::IKitObject&
	GetData() override;

	[[nodiscard]] const core::IKitObject&
	GetData() const override;

	void
	SetData(std::unique_ptr<core::IKitObject> data) override;

	[[nodiscard]] bool
	IsEmpty() const override;

	[[nodiscard]] std::string
	ToString() const override;

protected:
	int m_index;
	std::unique_ptr<core::IKitObject> m_data;
};
} // namespace gamekit::gameplay::inventory

#endif //  GAMEKIT_INCLUDE_GAMEKIT_GAMEPLAY_INVENTORY_BASE_INVENTORY_SLOT_H
