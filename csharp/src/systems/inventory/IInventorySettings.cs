
namespace Gamekit.Systems.Inventory
{
    public interface IInventorySettings
    {
        int GetMaxCapacity();
        int GetInitialCapacity();
        void SetMaxCapacity(int maxCapacity);
        void SetInitialCapacity(int initialCapacity);
    }
}
