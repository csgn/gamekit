// IWYU pragma: private, include "gamekit/gamekit.h"
// IWYU pragma: friend gamekit/.*
// IWYU pragma: friend gamekit_api/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H

#include <memory>
#include <string>

#include "gamekit/copyright.h"
#include "gamekit/core/core.h"

namespace gamekit::systems::inventory
{

/**
 * @brief Interface for a single inventory slot.
 *
 * Represents a container for inventory data of IKitObject.
 *
 */
class IInventorySlot
{
public:
	virtual ~IInventorySlot() = default;

	/**
	 * @brief Gets the index of the slot.
	 * @return Slot index.
	 */
	[[nodiscard]] virtual int
	GetIndex() const = 0;

	/**
	 * @brief Gets a pointer to the slot data.
	 * @return Reference to TData..
	 */
	virtual core::IKitObject&
	GetData() = 0;

	/**
	 * @brief Gets a const pointer to the slot data.
	 * @return Const reference to TData.
	 */
	[[nodiscard]] virtual const core::IKitObject&
	GetData() const = 0;

	/**
	 * @brief Sets the slot data.
	 * @param data Unique pointer to the data to store.
	 */
	virtual void
	SetData(std::unique_ptr<core::IKitObject> data) = 0;

	/**
	 * @brief Checks if the slot is empty.
	 * @return True if the slot has no data.
	 */
	[[nodiscard]] virtual bool
	IsEmpty() const = 0;

	/**
	 * @brief Returns a string representation of the slot.
	 * @return String describing the slot content.
	 */
	[[nodiscard]] virtual std::string
	ToString() const = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H
