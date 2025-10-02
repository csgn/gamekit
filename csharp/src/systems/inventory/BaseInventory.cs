using Microsoft.Win32.SafeHandles;
using System.Runtime.InteropServices;

namespace Gamekit.Systems.Inventory
{
    internal class BaseInventoryHandle : NativeHandle
    {
        private BaseInventoryHandle() : base(true) { }

        internal BaseInventoryHandle(BaseInventoryHandle nativeHandle, bool ownsHandle) : base(nativeHandle, ownsHandle)
        {
        }

        override protected bool ReleaseHandle()
        {
            BaseInventoryNativeMethods.GamekitAPI_BaseInventory_Delete(handle);
            return true;
        }

        internal override BaseInventoryHandle WithOwnership(bool ownsHandle)
        {
            return new BaseInventoryHandle(this, ownsHandle);
        }
    }

    internal static class BaseInventoryNativeMethods
    {
        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventory_New", CallingConvention = Platform.CC)]
        internal static extern BaseInventoryHandle GamekitAPI_BaseInventory_New(BaseInventorySettingsHandle settingsHandle);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventory_Delete", CallingConvention = Platform.CC)]
        internal static extern void GamekitAPI_BaseInventory_Delete(IntPtr handle);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventory_Initialize", CallingConvention = Platform.CC)]
        internal static extern bool GamekitAPI_BaseInventory_Initialize(BaseInventoryHandle handle, int initial_capacity);

        [DllImport(Platform.LibraryName, EntryPoint = "GamekitAPI_BaseInventory_GetSettings", CallingConvention = Platform.CC)]
        internal static extern BaseInventorySettingsHandle GamekitAPI_BaseInventory_GetSettings(BaseInventoryHandle handle);
    }

    public class BaseInventory : IInventory, IHandleContainer<BaseInventoryHandle>
    {
        internal BaseInventoryHandle _handle;

        private bool _initialized;

        public BaseInventory(BaseInventorySettings inventorySettings)
        {
            if (inventorySettings is IHandleContainer<BaseInventorySettingsHandle> inventorySettingsContainer)
            {
                inventorySettingsContainer.ChangeOwnership(false);
                _handle = BaseInventoryNativeMethods.GamekitAPI_BaseInventory_New(inventorySettingsContainer.Handle);
            }
        }

        BaseInventoryHandle IHandleContainer<BaseInventoryHandle>.Handle => _handle;

        void IHandleContainer<BaseInventoryHandle>.ChangeOwnership(bool ownsHandle)
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

        public bool Initialize(int? initial_capacity = 0)
        {
            _initialized = BaseInventoryNativeMethods
                .GamekitAPI_BaseInventory_Initialize(_handle, initial_capacity.GetValueOrDefault(0));
            return _initialized;
        }

        public bool IsInitialized()
        {
            return _initialized;
        }

        public BaseInventorySettings GetSettings()
        {
            var settingsHandle = BaseInventoryNativeMethods.GamekitAPI_BaseInventory_GetSettings(_handle);
            return new BaseInventorySettings(settingsHandle.WithOwnership(false));
        }
    }
}
