namespace Gamekit
{
    internal interface IHandleContainer<THandle> : IDisposable
        where THandle : NativeHandle
    {
        THandle Handle { get; }
        void ChangeOwnership(bool ownsHandle);
    }
}
