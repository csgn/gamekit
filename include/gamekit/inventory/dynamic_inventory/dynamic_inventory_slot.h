#ifndef GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
#define GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
#pragma once

#include "gamekit/inventory/iinventory_slot.h"

struct IGameObject;

class DynamicInventorySlot : public IInventorySlot<IGameObject>
{
};

#endif // GAMEKIT_DYNAMIC_INVENTORY_SLOT_H
