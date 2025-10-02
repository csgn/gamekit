namespace Gamekit
{
    internal abstract class NativeResource<THandle> : IDisposable
        where THandle : NativeHandle
    {
        protected THandle _handle;

        protected NativeResource(THandle handle)
        {
            _handle = handle ?? throw new ArgumentNullException(nameof(handle));
        }

        internal THandle GetHandle()
        {
            return _handle;
        }

        public void Dispose()
        {
            _handle?.Dispose();
            _handle = null!;
            GC.SuppressFinalize(this);
        }
    }
}
