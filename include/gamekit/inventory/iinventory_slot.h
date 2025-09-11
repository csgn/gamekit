#ifndef IINVENTORY_SLOT_H
#define IINVENTORY_SLOT_H
#pragma once

template<typename TData>
class IInventorySlot
{
public:
	virtual ~IInventorySlot() = default;

	virtual const int GetIndex() const = 0;
	virtual const TData GetData() const = 0;

	bool IsEmpty() const { return GetData() == nullptr; }
};

#endif //IINVENTORY_SLOT_H
