# Custom triplet for x86 and PHP <= 8.3 to use v142 toolset (Visual Studio 2019 vs16/14.29.30133) to match PHP build
set(VCPKG_TARGET_ARCHITECTURE x86)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE static)
set(VCPKG_PLATFORM_TOOLSET v142)
