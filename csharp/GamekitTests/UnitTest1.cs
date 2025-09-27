using NUnit.Framework;
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
            var inventory_settings = new DynamicInventorySettings(10, 5, false, 5, false);
            var maxCapacity = inventory_settings.GetMaxCapacity();
            Console.WriteLine(maxCapacity);
        }
    }
}
