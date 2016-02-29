This is a pack of libraries required to run and compile OctaForge on
the Windows operating system.

bin_win32 contains DLLs required to run Win32 builds of OctaForge. Copy
these into your bin_win32 directories.

bin_win64 contains DLLs required to run Win64 builds of OctaForge. Do
the same.

The "platform_windows" directory contains import libs of SDL and zlib,
LuaJIT static libraries and headers required to compile OctaForge on
Windows (both Win32 and Win64, feel free to remove whichever you don't
need). Copy the platform_windows directory into the src/ directory of
OctaForge in order to compile.

SDL2+_mixer,_image and zlib are zlib licensed.
LuaJIT is MIT licensed.
