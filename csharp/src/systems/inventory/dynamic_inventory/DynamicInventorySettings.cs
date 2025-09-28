using System.Runtime.InteropServices;

namespace Gamekit.Systems.Inventory.DynamicInventory
{
    public class DynamicInventorySettings(int maxCapacity, int initialCapacity, bool isExpandable, int slotsPerExpansion, bool isAutoExpand)
        : IDisposable
    {
        private readonly IntPtr m_nativePtr = GamekitAPI_DynamicInventorySettings_New(maxCapacity, initialCapacity, isExpandable, slotsPerExpansion, isAutoExpand);

        ~DynamicInventorySettings()
        {
            Dispose(false);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        private void Dispose(bool disposing)
        {
            if (!disposing)
            {
                if (m_nativePtr != IntPtr.Zero)
                {
                    GamekitAPI_DynamicInventorySettings_Delete(m_nativePtr);
                }
            }
        }

        public int GetMaxCapacity()
        {
            return GamekitAPI_DynamicInventorySettings_GetMaxCapacity(m_nativePtr);
        }

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_New", CallingConvention = Platform.CC)]
        private static extern IntPtr GamekitAPI_DynamicInventorySettings_New(int maxCapacity, int initialCapacity, bool isExpandable, int slotsPerExpansion, bool isAutoExpand);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_Delete", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_Delete(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetMaxCapacity", CallingConvention = Platform.CC)]
        private static extern int GamekitAPI_DynamicInventorySettings_GetMaxCapacity(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetInitialCapacity", CallingConvention = Platform.CC)]
        private static extern int GamekitAPI_DynamicInventorySettings_GetInitialCapacity(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetIsExpandable", CallingConvention = Platform.CC)]
        private static extern bool GamekitAPI_DynamicInventorySettings_GetIsExpandable(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion", CallingConvention = Platform.CC)]
        private static extern int GamekitAPI_DynamicInventorySettings_GetSlotsPerExpansion(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_GetIsAutoExpand", CallingConvention = Platform.CC)]
        private static extern bool GamekitAPI_DynamicInventorySettings_GetIsAutoExpand(IntPtr dynamicInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetMaxCapacity", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_SetMaxCapacity(IntPtr dynamicInventorySettings, int maxCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetInitialCapacity", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_SetInitialCapacity(IntPtr dynamicInventorySettings, int initialCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetIsExpandable", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_SetIsExpandable(IntPtr dynamicInventorySettings, bool isExpandable);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_SetSlotsPerExpansion(IntPtr dynamicInventorySettings, int slotsPerExpansion);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_DynamicInventorySettings_SetIsAutoExpand", CallingConvention = Platform.CC)]
        private static extern void GamekitAPI_DynamicInventorySettings_SetIsAutoExpand(IntPtr dynamicInventorySettings, bool isAutoExpand);
    }
}
