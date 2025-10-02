namespace Gamekit.Systems.Inventory
{
    public interface IInventory
    {
        bool Initialize(int? initial_capacity);
        BaseInventorySettings GetSettings();

        bool IsInitialized();
    }
}
