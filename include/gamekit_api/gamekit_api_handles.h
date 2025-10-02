// IWYU pragma: private, include "gamekit/gamekit_api.h"
// IWYU pragma: friend gamekit_api/.*
// IWYU pragma: friend gamekit/.*

#ifndef GAMEKIT_INCLUDE_GAMEKIT_API_GAMEKIT_API_HANDLES_H
#define GAMEKIT_INCLUDE_GAMEKIT_API_GAMEKIT_API_HANDLES_H

#include "gamekit/core/core.h"
#include "gamekit/systems/inventory/inventory.h"

using gamekit::core::IKitObject;
using gamekit::systems::inventory::IInventory;
using gamekit::systems::inventory::IInventorySlot;
using gamekit::systems::inventory::IInventorySettings;
using gamekit::systems::inventory::BaseInventory;
using gamekit::systems::inventory::BaseInventorySlot;
using gamekit::systems::inventory::BaseInventorySettings;

namespace gamekit_api
{

struct HKitObject;
struct HInventory;
struct HInventorySlot;
struct HInventorySettings;

typedef struct HKitObject HKitObject;
typedef struct HInventory HInventory;
typedef struct HInventorySettings HInventorySettings;
typedef struct HInventorySlot HInventorySlot;
} // namespace gamekit_api

#endif // GAMEKIT_INCLUDE_GAMEKIT_API_GAMEKIT_API_HANDLES_H
