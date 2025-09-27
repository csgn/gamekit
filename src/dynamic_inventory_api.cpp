#include "gamekit/copyright.h"
#include "gamekit/gamekit.h"
#include "gamekit/gamekit_api.h"

namespace gamekit::systems::inventory::dynamic_inventory::api
{

GAMEKIT_API DynamicInventorySettings* CALL_TYPE GamekitAPI_DynamicInventorySettings_New(const int max_capacity,
																						const int initial_capacity,
																						const bool is_expandable,
																						const int slots_per_expansion,
																						const bool is_auto_expand)
{
	return new DynamicInventorySettings(max_capacity, initial_capacity, is_expandable, slots_per_expansion,
										is_auto_expand);
}

} // namespace gamekit::systems::inventory::dynamic_inventory::api
