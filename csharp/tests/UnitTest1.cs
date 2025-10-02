using Gamekit.Systems.Inventory;

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
            int maxCapacity = 10;
            int initialCapacity = 5;

            // Act
            var settings = new BaseInventorySettings(maxCapacity, initialCapacity);
            using var inventory = new BaseInventory(settings);
            var initialized = inventory.Initialize();

            // Assert
            Assert.That(initialized, Is.True);
            Assert.That(inventory.IsInitialized(), Is.True);
            Assert.That(inventory.IsInitialized(), Is.EqualTo(initialized));

            Assert.That(settings.GetMaxCapacity(), Is.EqualTo(maxCapacity));
            Assert.That(inventory.GetSettings().GetMaxCapacity(), Is.EqualTo(maxCapacity));
            Assert.That(inventory.GetSettings().GetMaxCapacity(), Is.EqualTo(settings.GetMaxCapacity()));

            Assert.That(settings.GetInitialCapacity(), Is.EqualTo(initialCapacity));
            Assert.That(inventory.GetSettings().GetInitialCapacity(), Is.EqualTo(settings.GetInitialCapacity()));
            Assert.That(inventory.GetSettings().GetInitialCapacity(), Is.EqualTo(initialCapacity));
        }
    }
}
