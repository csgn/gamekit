using Microsoft.Win32.SafeHandles;
using System.Runtime.InteropServices;

namespace Gamekit
{
    internal abstract class NativeHandle : SafeHandleZeroOrMinusOneIsInvalid
    {
        protected NativeHandle(bool ownsHandle = true) : base(ownsHandle) { }

        internal NativeHandle(IntPtr handle, bool ownsHandle = true) : base(ownsHandle)
        {
            SetHandle(handle);
        }

        internal NativeHandle(NativeHandle nativeHandle, bool ownsHandle = true) : this(nativeHandle.handle, ownsHandle)
        {

        }

        internal bool IsNull()
        {
            return handle == IntPtr.Zero;
        }

        internal abstract NativeHandle WithOwnership(bool ownsHandle);
    }
}
