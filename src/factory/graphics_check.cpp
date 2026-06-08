#include "graphics_check.h"

#include <cstdlib>

bool GraphicsCheck::hasGraphics() {
    const char* display = std::getenv("DISPLAY");
    const char* wayland = std::getenv("WAYLAND_DISPLAY");

    return (display != nullptr) || (wayland != nullptr);
}