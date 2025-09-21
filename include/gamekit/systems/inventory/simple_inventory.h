// IWYU pragma: private, include "gamekit/gamekit.h"

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H

#include <memory>
#include <utility>

#include "gamekit/systems/inventory/base_inventory.h" // IWYU pragma: export

namespace gamekit::systems::inventory
{

class SimpleInventorySettings : public BaseInventorySettings
{
public:
	explicit SimpleInventorySettings(const int max_capacity, const int initial_capacity) :
		BaseInventorySettings(max_capacity, initial_capacity)
	{
	}
};

template<typename TData>
class SimpleInventorySlot : public BaseInventorySlot<TData>
{
public:
	explicit SimpleInventorySlot(const int index) : BaseInventorySlot<TData>(index) {}

	[[nodiscard]] std::string ToString() const override
	{
		std::stringstream ss;
		ss << "SimpleInventorySlot(" << this->m_index << ", " << (this->IsEmpty() ? "Empty" : "...") << ")";
		return ss.str();
	}
};

template<typename TData>
class SimpleInventory : public BaseInventory<TData, SimpleInventorySettings, SimpleInventorySlot<TData>>
{
public:
	using Base = BaseInventory<TData, SimpleInventorySettings, SimpleInventorySlot<TData>>;

	explicit SimpleInventory(std::unique_ptr<SimpleInventorySettings> settings) : Base(std::move(settings)) {}
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_SIMPLE_INVENTORY_H
