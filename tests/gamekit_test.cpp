#include <gamekit/gamekit.h>
#include <gtest/gtest.h>

// [ClassName]_[MethodOrScenario]_Should[ExpectedBehavior]_When[Condition]

TEST(InventoryTestSuite, DynamicInventory_Constructor_ShouldCreatedCorrectly_WhenValidSettingsProvided)
{
	constexpr auto max_capacity = 20;
	constexpr auto initial_capacity = 10;
	const auto settings = DynamicInventorySettings(max_capacity, initial_capacity);
	const auto di = DynamicInventory(settings);

	EXPECT_EQ(di.GetSettings().GetMaxCapacity(), max_capacity);
	EXPECT_EQ(di.GetSettings().GetInitialCapacity(), initial_capacity);
}

TEST(InventoryTestSuite, DynamicInventory_Constructor_ShouldThrowInvalidArgument_WhenInvalidCapacity)
{
	constexpr auto max_capacity = 10;
	constexpr auto initial_capacity = 20;
	EXPECT_THROW(DynamicInventorySettings(max_capacity, initial_capacity), std::invalid_argument);
}

TEST(InventoryTestSuite, DynamicInventory_Initialize_ShouldInitializeCorrectly_WhenValidSettingsProvided)
{
	constexpr auto max_capacity = 20;
	constexpr auto initial_capacity = 10;
	const auto settings = DynamicInventorySettings(max_capacity, initial_capacity);
	auto di = DynamicInventory(settings);
	const auto result = di.Initialize();

	EXPECT_EQ(settings.GetMaxCapacity(), max_capacity);
	EXPECT_EQ(settings.GetInitialCapacity(), initial_capacity);
	EXPECT_TRUE(result);
}