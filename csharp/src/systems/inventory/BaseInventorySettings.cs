using System.Runtime.InteropServices;

namespace Gamekit.Systems.Inventory
{
    public class BaseInventorySettings : NativeObject, IInventorySettings
    {
        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_New", CallingConvention = Platform.CC)]
        internal static extern IntPtr GamekitAPI_BaseInventorySettings_New(int maxCapacity, int initialCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_Delete", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_Delete(IntPtr baseInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_GetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_BaseInventorySettings_GetMaxCapacity(IntPtr baseInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_GetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_BaseInventorySettings_GetInitialCapacity(IntPtr baseInventorySettings);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_SetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_SetMaxCapacity(IntPtr baseInventorySettings, int maxCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_SetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_SetInitialCapacity(IntPtr baseInventorySettings, int initialCapacity);

        public BaseInventorySettings() { }

        public BaseInventorySettings(int maxCapacity, int initialCapacity)
        {
            _mPtr = GamekitAPI_BaseInventorySettings_New(maxCapacity, initialCapacity);
        }

        protected override void FreePtr()
        {
            GamekitAPI_BaseInventorySettings_Delete(_mPtr);
        }

        public virtual int GetMaxCapacity()
        {
            return GamekitAPI_BaseInventorySettings_GetMaxCapacity(_mPtr);
        }

        public virtual int GetInitialCapacity()
        {
            return GamekitAPI_BaseInventorySettings_GetInitialCapacity(_mPtr);
        }

        public virtual void SetMaxCapacity(int maxCapacity)
        {
            GamekitAPI_BaseInventorySettings_SetMaxCapacity(_mPtr, maxCapacity);
        }

        public virtual void SetInitialCapacity(int initialCapacity)
        {
            GamekitAPI_BaseInventorySettings_SetInitialCapacity(_mPtr, initialCapacity);
        }
    }
}
