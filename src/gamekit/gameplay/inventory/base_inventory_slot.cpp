#include <memory>
#include <sstream>
#include <string>
#include <utility>

#include "gamekit/copyright.h"
#include "gamekit/core/ikitobject.h"
#include "gamekit/gameplay/inventory/base_inventory_slot.h"

namespace gamekit::gameplay::inventory
{

int
BaseInventorySlot::GetIndex() const
{
	return m_index;
}

core::IKitObject&
BaseInventorySlot::GetData()
{
	return *m_data;
}

const core::IKitObject&
BaseInventorySlot::GetData() const
{
	return *m_data;
}

void
BaseInventorySlot::SetData(std::unique_ptr<core::IKitObject> data)
{
	m_data = std::move(data);
}

bool
BaseInventorySlot::IsEmpty() const
{
	return m_data == nullptr;
}

std::string
BaseInventorySlot::ToString() const
{
	std::stringstream ss;
	ss << "BaseInventorySlot(" << m_index << ", " << (IsEmpty() ? "Empty" : "...") << ")";
	return ss.str();
}

} // namespace gamekit::gameplay::inventory

