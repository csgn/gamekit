// IWYU pragma: private, include "gamekit/gamekit.h"
//
#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H_
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H_

#include <memory>
#include <string>

namespace gamekit::systems::inventory
{

/**
 * @brief Interface for a single inventory slot.
 *
 * Represents a container for inventory data of type TData.
 *
 * @tparam TData Type of data stored in the slot. Typically derives from @ref IGameObject.
 *
 * @see IGameObject
 */
template<typename TData>
class IInventorySlot
{
public:
	virtual ~IInventorySlot() = default;

	/**
	 * @brief Gets the index of the slot.
	 * @return Slot index.
	 */
	virtual int GetIndex() const = 0;

	/**
	 * @brief Gets a pointer to the slot data.
	 * @return Reference to TData..
	 */
	virtual TData& GetData() = 0;

	/**
	 * @brief Gets a const pointer to the slot data.
	 * @return Const reference to TData.
	 */
	virtual const TData& GetData() const = 0;

	/**
	 * @brief Sets the slot data.
	 * @param data Unique pointer to the data to store.
	 */
	virtual void SetData(std::unique_ptr<TData> data) = 0;

	/**
	 * @brief Checks if the slot is empty.
	 * @return True if the slot has no data.
	 */
	virtual bool IsEmpty() const = 0;

	/**
	 * @brief Returns a string representation of the slot.
	 * @return String describing the slot content.
	 */
	virtual std::string ToString() const = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SLOT_H_
