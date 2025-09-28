using Gamekit.Systems.Inventory;
using Gamekit.Systems.Inventory.DynamicInventory;

namespace Gamekit.Tests
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Test1()
        {
            // Arrange
            int maxCapacity = 100;
            int initialCapacity = 50;
            bool isExpandable = true;
            int slotsPerExpansion = 10;
            bool isAutoExpand = true;

            // Act
            using var settings = new DynamicInventorySettings(maxCapacity, initialCapacity, isExpandable, slotsPerExpansion, isAutoExpand);

            // Assert
            Assert.That(settings.GetMaxCapacity(), Is.EqualTo(maxCapacity));
            Assert.That(settings.GetInitialCapacity(), Is.EqualTo(initialCapacity));
            Assert.That(settings.GetIsExpandable(), Is.EqualTo(isExpandable));
            Assert.That(settings.GetSlotsPerExpansion(), Is.EqualTo(slotsPerExpansion));
            Assert.That(settings.GetIsAutoExpand(), Is.EqualTo(isAutoExpand));

            // Act
            settings.SetMaxCapacity(120);
            settings.SetInitialCapacity(60);
            settings.SetExpandable(false);
            settings.SetSlotsPerExpansion(5);
            settings.SetAutoExpand(false);

            // Assert
            Assert.That(settings.GetMaxCapacity(), Is.EqualTo(120));
            Assert.That(settings.GetInitialCapacity(), Is.EqualTo(60));
            Assert.That(settings.GetIsExpandable(), Is.EqualTo(false));
            Assert.That(settings.GetSlotsPerExpansion(), Is.EqualTo(5));
            Assert.That(settings.GetIsAutoExpand(), Is.EqualTo(false));
        }
    }
}
