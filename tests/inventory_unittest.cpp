#include <gamekit/gamekit.h>
#include <gtest/gtest.h>
#include <memory>

class TestInventoryData : public IGameObject
{
private:
	int m_id;

public:
	int GetID() const override { return m_id; }
};

TEST(SimpleInventoryTest, Initialize)
{
	// Arrange
	std::unique_ptr<SimpleInventorySettings> inventory_settings = std::make_unique<SimpleInventorySettings>();
	inventory_settings->SetMaxCapacity(20);
	inventory_settings->SetInitialCapacity(10);

	SimpleInventory<TestInventoryData> inventory(std::move(inventory_settings));

	// Act
	bool result = inventory.Initialize();

	// Assert
	EXPECT_TRUE(result);
	EXPECT_EQ(10, inventory.GetCapacity());
	EXPECT_EQ(0, inventory.GetOccupiedSlotCount());
	EXPECT_EQ(20, inventory.GetSettings()->GetMaxCapacity());
	EXPECT_EQ(10, inventory.GetSettings()->GetInitialCapacity());
}
