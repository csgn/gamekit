#ifndef GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
#define GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
#pragma once

#include "gamekit/inventory/iinventory_slot.h"

struct IGameObject;

class DynamicInventorySlot final : public IInventorySlot<IGameObject>
{
public:
	//const int GetIndex() const override;
	//const IGameObject& GetData() const override;
};

#endif // GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
