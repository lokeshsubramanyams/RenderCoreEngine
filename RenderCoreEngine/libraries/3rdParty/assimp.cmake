list(APPEND CMAKE_MODULE_PATH "${VCPKG_INSTALL_X64-WINDOWS_STATIC}/share/stb")#assimp dependecy
find_package(assimp REQUIRED)