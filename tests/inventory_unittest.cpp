#include <gamekit/gamekit.h>
#include <gtest/gtest.h>
#include <memory>

namespace gamekit::tests
{
using namespace std;
using namespace gamekit::core;
using namespace gamekit::systems::inventory;

class TestInventoryData final : public IGameObject
{
private:
	int m_id;
	string m_name;

public:
	explicit TestInventoryData(const int id, const string& name) : m_id(id), m_name(name) {}
	int GetID() const override { return m_id; }
};

TEST(SimpleInventoryTest, Initialize)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(10, inventory.GetCapacity());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());
	ASSERT_EQ(20, inventory.GetSettings().GetMaxCapacity());
	ASSERT_EQ(10, inventory.GetSettings().GetInitialCapacity());
}

TEST(SimpleInventoryTest, GetSettings)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	const SimpleInventorySettings& settings = inventory.GetSettings();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(20, settings.GetMaxCapacity());
	ASSERT_EQ(10, settings.GetInitialCapacity());
}

TEST(SimpleInventoryTest, GetSlots)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	const vector<SimpleInventorySlot<TestInventoryData>>& slots = inventory.GetSlots();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(10, inventory.GetCapacity());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());

	int i = 0;
	for (const SimpleInventorySlot<TestInventoryData>& slot : slots)
	{
		ASSERT_TRUE(slot.IsEmpty());
		ASSERT_EQ(i, slot.GetIndex());

		stringstream ss;
		ss << "SimpleInventorySlot(" << i << ", " << "Empty" << ")";
		ASSERT_EQ(ss.str(), slot.ToString());

		i++;
	}
}

TEST(SimpleInventoryTest, Add)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	const std::optional<std::vector<int>> filled_indices_0 = inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	const std::optional<std::vector<int>> filled_indices_1 = inventory.Add(make_unique<TestInventoryData>(2, "Potion"));

	// Assert
	ASSERT_TRUE(result);
	ASSERT_EQ(2, inventory.GetOccupiedSlotCount());
	ASSERT_TRUE(filled_indices_0.has_value());
	ASSERT_TRUE(filled_indices_1.has_value());
	ASSERT_EQ(0, filled_indices_0->at(0));
	ASSERT_EQ(1, filled_indices_1->at(0));

	const SimpleInventorySlot<TestInventoryData>& slot_0 = inventory.GetSlot(0);
	const SimpleInventorySlot<TestInventoryData>& slot_1 = inventory.GetSlot(1);

	ASSERT_FALSE(slot_0.IsEmpty());
	ASSERT_FALSE(slot_1.IsEmpty());
	ASSERT_EQ(0, slot_0.GetIndex());
	ASSERT_EQ(1, slot_1.GetIndex());
	ASSERT_EQ(1, slot_0.GetData().GetID());
}

TEST(SimpleInventoryTest, Remove)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));

	const bool remove_result = inventory.Remove(0);
	const SimpleInventorySlot<TestInventoryData>& slot_0 = inventory.GetSlot(0);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(remove_result);
	ASSERT_TRUE(slot_0.IsEmpty());
	ASSERT_EQ(0, inventory.GetOccupiedSlotCount());
}

TEST(SimpleInventoryTest, FindAnEmptySlot)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(20, 10);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
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

TEST(SimpleInventoryTest, HasInventoryEmptySlot)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(10, 3);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
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

TEST(SimpleInventoryTest, IsSlotOccupied)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(10, 3);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));

	const bool is_slot0_occupied = inventory.IsSlotOccupied(0);
	const bool is_slot1_occupied = inventory.IsSlotOccupied(1);

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(is_slot0_occupied);
	ASSERT_FALSE(is_slot1_occupied);
}

TEST(SimpleInventoryTest, IsInventoryFull)
{
	// Arrange
	unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>(10, 2);
	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	const bool result = inventory.Initialize();
	inventory.Add(make_unique<TestInventoryData>(1, "Apple"));
	inventory.Add(make_unique<TestInventoryData>(2, "Apple"));

	const bool is_inventory_full = inventory.IsInventoryFull();

	// Assert
	ASSERT_TRUE(result);
	ASSERT_TRUE(is_inventory_full);
}

} // namespace gamekit::tests
