using System.Runtime.InteropServices;

namespace Gamekit
{
    internal static class Platform
    {
#if PLATFORM_WIN64
		public const string LibraryName = "gamekit";
#elif PLATFORM_POSIX
		public const string LibraryName = "libgamekit";
#else
        public const string LibraryName = "NO_LIBRARY_ASSIGNED";
#endif

        public const CallingConvention CC = CallingConvention.Cdecl;
    }
}
