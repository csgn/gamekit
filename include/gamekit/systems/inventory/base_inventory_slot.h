// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H

#include <memory>
#include <sstream>
#include <string>
#include <utility>

#include "gamekit/copyright.h"
#include "gamekit/core/core.h"
#include "gamekit/systems/inventory/iinventory_slot.h"

namespace gamekit::systems::inventory
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
	GetIndex() const override
	{
		return m_index;
	}

	core::IKitObject&
	GetData() override
	{
		return *m_data;
	}

	[[nodiscard]] const core::IKitObject&
	GetData() const override
	{
		return *m_data;
	}

	void
	SetData(std::unique_ptr<core::IKitObject> data) override
	{
		m_data = std::move(data);
	}

	[[nodiscard]] bool
	IsEmpty() const override
	{
		return m_data == nullptr;
	}

	[[nodiscard]] std::string
	ToString() const override
	{
		std::stringstream ss;
		ss << "BaseInventorySlot(" << m_index << ", " << (IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}

protected:
	int m_index;
	std::unique_ptr<core::IKitObject> m_data;
};
} // namespace gamekit::systems::inventory

#endif //  GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H
