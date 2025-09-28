namespace Gamekit
{
    public abstract class NativeObject : IDisposable
    {
        protected IntPtr _mPtr;

        protected NativeObject() { }

        protected NativeObject(IntPtr ptr)
        {
            _mPtr = ptr;
        }

        ~NativeObject()
        {
            Dispose(false);
        }

        protected abstract void FreePtr();

        protected bool IsPtrNull()
        {
            return _mPtr == IntPtr.Zero;
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (!IsPtrNull())
            {
                FreePtr();
                _mPtr = IntPtr.Zero;
            }

            if (disposing)
            {
                DisposeManaged();
            }
        }

        protected virtual void DisposeManaged() { }
    }
}
