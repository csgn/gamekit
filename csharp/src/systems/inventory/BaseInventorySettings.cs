using Microsoft.Win32.SafeHandles;
using System.Runtime.InteropServices;

namespace Gamekit.Systems.Inventory
{
    internal class BaseInventorySettingsHandle : NativeHandle
    {
        private BaseInventorySettingsHandle() : base(true) { }

        internal BaseInventorySettingsHandle(BaseInventorySettingsHandle nativeHandle, bool ownsHandle) : base(nativeHandle, ownsHandle)
        {

        }

        override protected bool ReleaseHandle()
        {
            BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_Delete(handle);
            return true;
        }

        internal override BaseInventorySettingsHandle WithOwnership(bool ownsHandle)
        {
            return new BaseInventorySettingsHandle(this, ownsHandle);
        }
    }

    internal static class BaseInventorySettingsNativeMethods
    {
        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_New", CallingConvention = Platform.CC)]
        internal static extern BaseInventorySettingsHandle GamekitAPI_BaseInventorySettings_New(int maxCapacity, int initialCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_Delete", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_Delete(IntPtr handle);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_GetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_BaseInventorySettings_GetMaxCapacity(BaseInventorySettingsHandle handle);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_GetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern int GamekitAPI_BaseInventorySettings_GetInitialCapacity(BaseInventorySettingsHandle handle);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_SetMaxCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_SetMaxCapacity(BaseInventorySettingsHandle handle, int maxCapacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventorySettings_SetInitialCapacity", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventorySettings_SetInitialCapacity(BaseInventorySettingsHandle handle, int initialCapacity);
    }

    public class BaseInventorySettings : IInventorySettings, IHandleContainer<BaseInventorySettingsHandle>
    {
        internal BaseInventorySettingsHandle _handle;

        internal BaseInventorySettings(BaseInventorySettingsHandle handle)
        {
            _handle = handle;
        }

        public BaseInventorySettings(int maxCapacity, int initialCapacity)
        {
            _handle = BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_New(maxCapacity, initialCapacity);
        }

        BaseInventorySettingsHandle IHandleContainer<BaseInventorySettingsHandle>.Handle => _handle;

        void IHandleContainer<BaseInventorySettingsHandle>.ChangeOwnership(bool ownsHandle)
        {
            _handle = _handle.WithOwnership(ownsHandle);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!_handle.IsNull() && !_handle.IsInvalid)
            {
                _handle.Dispose();
            }
        }

        public int GetMaxCapacity()
        {
            return BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_GetMaxCapacity(_handle);
        }

        public int GetInitialCapacity()
        {
            return BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_GetInitialCapacity(_handle);
        }

        public void SetMaxCapacity(int maxCapacity)
        {
            BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_SetMaxCapacity(_handle, maxCapacity);
        }

        public void SetInitialCapacity(int initialCapacity)
        {
            BaseInventorySettingsNativeMethods.GamekitAPI_BaseInventorySettings_SetInitialCapacity(_handle, initialCapacity);
        }
    }
}
