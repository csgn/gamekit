#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "gamekit/copyright.h"

#include "gamekit/gamekit.h"
#include "gtest/gtest.h"

namespace gamekit::tests
{
using namespace std;
using namespace gamekit::core;
using namespace gamekit::systems::inventory;
using namespace gamekit::systems::inventory::static_inventory;

class TestInventoryData final : public IGameObject
{
private:
	int m_id;
	string m_name;

public:
	explicit TestInventoryData(const int id, string name) : m_id(id), m_name(std::move(name)) {}
	[[nodiscard]] int GetID() const override { return m_id; }
};

TEST(StaticInventoryTest, Initialize)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(10, inventory.GetCapacity());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());
	ASSERT_EQ(20, inventory.GetSettings().GetMaxCapacity());
	ASSERT_EQ(10, inventory.GetSettings().GetInitialCapacity());
}

TEST(StaticInventoryTest, GetSettings)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	const StaticInventorySettings& settings = inventory.GetSettings();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(20, settings.GetMaxCapacity());
	ASSERT_EQ(10, settings.GetInitialCapacity());
}

TEST(StaticInventoryTest, GetSlots)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	const vector<StaticInventorySlot<TestInventoryData>>& slots = inventory.GetSlots();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(10, inventory.GetCapacity());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());

	int i = 0;
	for (const StaticInventorySlot<TestInventoryData>& slot: slots)
	{
		ASSERT_TRUE(slot.IsEmpty());
		ASSERT_EQ(i, slot.GetIndex());

		stringstream ss;
		ss << "StaticInventorySlot(" << i << ", "
		   << "Empty"
		   << ")";
		ASSERT_EQ(ss.str(), slot.ToString());

		i++;
	}
}

TEST(StaticInventoryTest, Add)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	const std::optional<std::vector<int>> filled_indices_0 = inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	const std::optional<std::vector<int>> filled_indices_1 = inventory.Add(make_unique<TestInventoryData>(2, "Potion"));

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(2, inventory.GetOccupiedSlotCount());
	ASSERT_TRUE(filled_indices_0.has_value());
	ASSERT_TRUE(filled_indices_1.has_value());
	ASSERT_EQ(0, filled_indices_0->at(0));
	ASSERT_EQ(1, filled_indices_1->at(0));

	const StaticInventorySlot<TestInventoryData>& slot_0 = inventory.GetSlot(0);
	const StaticInventorySlot<TestInventoryData>& slot_1 = inventory.GetSlot(1);

	ASSERT_FALSE(slot_0.IsEmpty());
	ASSERT_FALSE(slot_1.IsEmpty());
	ASSERT_EQ(0, slot_0.GetIndex());
	ASSERT_EQ(1, slot_1.GetIndex());
	ASSERT_EQ(1, slot_0.GetData().GetID());
}

TEST(StaticInventoryTest, Remove)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));

	const bool remove_result = inventory.Remove(0);
	const StaticInventorySlot<TestInventoryData>& slot_0 = inventory.GetSlot(0);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(remove_result);
	ASSERT_TRUE(slot_0.IsEmpty());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());
}

TEST(StaticInventoryTest, FindAnEmptySlot)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(20, 10);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(2, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(3, "Apple"));

	const optional<int> empty_slot_index = inventory.FindEmptySlot();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(3, inventory.GetOccupiedSlotCount());
	ASSERT_TRUE(empty_slot_index.has_value());
	ASSERT_EQ(3, empty_slot_index.value());
}

TEST(StaticInventoryTest, HasInventoryEmptySlot)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(10, 3);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(2, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(3, "Apple"));

	const bool has_empty_slot = inventory.HasInventoryEmptySlot();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_FALSE(has_empty_slot);
	ASSERT_EQ(3, inventory.GetOccupiedSlotCount());
	ASSERT_TRUE(inventory.IsInventoryFull());
}

TEST(StaticInventoryTest, IsSlotOccupied)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(10, 3);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));

	const bool is_slot0_occupied = inventory.IsSlotOccupied(0);
	const bool is_slot1_occupied = inventory.IsSlotOccupied(1);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(is_slot0_occupied);
	ASSERT_FALSE(is_slot1_occupied);
}

TEST(StaticInventoryTest, IsInventoryFull)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(10, 2);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(2, "Apple"));

	const bool is_inventory_full = inventory.IsInventoryFull();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(is_inventory_full);
}

TEST(StaticInventoryTest, IsSlotIndexInBounds)
{
	// Arrange
	unique_ptr<StaticInventorySettings> inventory_settings = std::make_unique<StaticInventorySettings>(10, 2);
	StaticInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize(nullopt);
	const bool is_0th_index_in_bounds = inventory.IsSlotIndexInBounds(0);
	const bool is_125th_index_not_in_bounds = inventory.IsSlotIndexInBounds(125);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(is_0th_index_in_bounds);
	ASSERT_FALSE(is_125th_index_not_in_bounds);
}

} // namespace gamekit::tests
