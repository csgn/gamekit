// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H

#include <memory>
#include <sstream>
#include <string>

#include "gamekit/copyright.h"

#include "gamekit/systems/inventory/iinventory_slot.h"

namespace gamekit::systems::inventory
{

/**
 * @brief Base inventory slot class template.
 *
 * Represents a single slot in an inventory. Each slot has an index and can
 * hold data of type TData. Provides basic slot functionalities such as
 * checking if the slot is empty and setting/getting the stored data.
 *
 * @tparam TData Type of data stored in the slot.
 */
template<typename TData>
class BaseInventorySlot : public IInventorySlot<TData>
{

public:
	/**
	 * @brief Base inventory slot class template.
	 *
	 * Represents a single slot in an inventory. Each slot has an index and can
	 * hold data of type TData.
	 *
	 * @tparam TData Type of data stored in the slot.
	 */
	explicit BaseInventorySlot(const int index) : m_index(index) {}

	[[nodiscard]] int
	GetIndex() const override
	{
		return m_index;
	}

	TData&
	GetData() override
	{
		return *m_data;
	}

	const TData&
	GetData() const override
	{
		return *m_data;
	}

	void
	SetData(std::unique_ptr<TData> data) override
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
	std::unique_ptr<TData> m_data;
};
} // namespace gamekit::systems::inventory

#endif //  GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_BASE_INVENTORY_SLOT_H
