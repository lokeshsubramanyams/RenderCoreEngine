
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(VCPKG_INSTALL_X64-WINDOWS_STATIC "C:/vcpkg/installed/x64-windows-static")

list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALL_X64-WINDOWS_STATIC}")

set(VCPKG_INCLUDE_DIR "${VCPKG_INSTALL_X64-WINDOWS_STATIC}/include")

add_library(vcpkg_interface INTERFACE)
target_include_directories(vcpkg_interface INTERFACE ${VCPKG_INCLUDE_DIR})