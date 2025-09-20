#ifndef GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H_
#define GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H_

namespace gamekit::systems::inventory
{

/**
 * @brief Interface for inventory configuration settings.
 *
 * Provides accessors and mutators for inventory capacities and behaviours.
 */
class IInventorySettings
{
public:
	virtual ~IInventorySettings() = default;

	/**
	 * @brief Gets the maximum allowed inventory capacity.
	 * @return Maximum number of slots.
	 */
	virtual const int GetMaxCapacity() const = 0;


	/**
	 * @brief Gets the initial inventory capacity.
	 * @return Number of slots at initialization.
	 */
	virtual const int GetInitialCapacity() const = 0;

	/**
	 * @brief Sets the maximum allowed inventory capacity.
	 * @param max_capacity Maximum number of slots.
	 */
	virtual void SetMaxCapacity(int max_capacity) = 0;


	/**
	 * @brief Sets the initial inventory capacity.
	 * @param initial_capacity Number of slots at initialization.
	 */
	virtual void SetInitialCapacity(int initial_capacity) = 0;
};

} // namespace gamekit::systems::inventory

#endif // GAMEKIT_INCLUDE_GAMEKIT_SYSTEMS_INVENTORY_IINVENTORY_SETTINGS_H_
