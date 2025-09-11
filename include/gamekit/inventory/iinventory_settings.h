#ifndef IINVENTORY_SETTINGS_H
#define IINVENTORY_SETTINGS_H
#pragma once

class IInventorySettings
{
public:
	virtual ~IInventorySettings() = default;

	virtual const int GetMaxCapacity() const = 0;
	virtual const int GetInitialCapacity() const = 0;

	virtual void SetMaxCapacity(int max_capacity) = 0;
	virtual void SetInitialCapacity(int initial_capacity) = 0;
};

#endif //IINVENTORY_SETTINGS_H
