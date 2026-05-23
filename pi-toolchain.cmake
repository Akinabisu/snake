set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(SYSROOT_PATH "$ENV{HOME}/rpi-sysroot")
set(CMAKE_SYSROOT ${SYSROOT_PATH})

set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)