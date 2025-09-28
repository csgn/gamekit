using System.Runtime.InteropServices;

namespace Gamekit.Systems.Inventory.DynamicInventory
{
    public class DynamicInventorySettings : BaseInventorySettings
    {
        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_New", CallingConvention = Platform.CC)]
        internal static extern IntPtr GamekitAPI_DynamicInventorySettings_New(int maxCapacity, int initialCapacity, bool isExpandable, int slotsPerExpansion, bool isAutoExpand);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_Delete", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_Delete(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_DynamicInventorySettings_GetMaxCapacity(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_DynamicInventorySettings_GetInitialCapacity(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetIsExpandable", CallingConvention = Platform.CC)]
        internal static extern bool GamekitAPI_DynamicInventorySettings_GetIsExpandable(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetIsAutoExpand", CallingConvention = Platform.CC)]
        internal static extern bool GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_SetMaxCapacity(IntPtr dynamicInventorySettings, int maxCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_SetInitialCapacity(IntPtr dynamicInventorySettings, int initialCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetExpandable", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_SetExpandable(IntPtr dynamicInventorySettings, bool isExpandable);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(IntPtr dynamicInventorySettings, int slotsPerExpansion);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetAutoExpand", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_DynamicInventorySettings_SetAutoExpand(IntPtr dynamicInventorySettings, bool isAutoExpand);

        public DynamicInventorySettings() { }

        public DynamicInventorySettings(int maxCapacity, int initialCapacity, bool isExpandable, int slotsPerExpansion, bool isAutoExpand)
        {
            _mPtr = GamekitAPI_DynamicInventorySettings_New(maxCapacity, initialCapacity, isExpandable, slotsPerExpansion, isAutoExpand);
        }

        protected override void FreePtr()
        {
            GamekitAPI_DynamicInventorySettings_Delete(_mPtr);
        }

        public override int GetMaxCapacity()
        {
            return GamekitAPI_DynamicInventorySettings_GetMaxCapacity(_mPtr);
        }

        public override int GetInitialCapacity()
        {
            return GamekitAPI_DynamicInventorySettings_GetInitialCapacity(_mPtr);
        }

        public virtual bool GetIsExpandable()
        {
            return GamekitAPI_DynamicInventorySettings_GetIsExpandable(_mPtr);
        }

        public virtual int GetSlotsPerExpansion()
        {
            return GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(_mPtr);
        }

        public virtual bool GetIsAutoExpand()
        {
            return GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(_mPtr);
        }

        public override void SetMaxCapacity(int maxCapacity)
        {
            GamekitAPI_DynamicInventorySettings_SetMaxCapacity(_mPtr, maxCapacity);
        }

        public override void SetInitialCapacity(int initialCapacity)
        {
            GamekitAPI_DynamicInventorySettings_SetInitialCapacity(_mPtr, initialCapacity);
        }

        public virtual void SetExpandable(bool isExpandable)
        {
            GamekitAPI_DynamicInventorySettings_SetExpandable(_mPtr, isExpandable);
        }

        public virtual void SetSlotsPerExpansion(int slotsPerExpansion)
        {
            GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(_mPtr, slotsPerExpansion);
        }

        public virtual void SetAutoExpand(bool isAutoExpand)
        {
            GamekitAPI_DynamicInventorySettings_SetAutoExpand(_mPtr, isAutoExpand);
        }
    }
}
