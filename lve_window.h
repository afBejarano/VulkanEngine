//
// Created by andre on 18/07/2024.
//
#ifndef VULKAN_LVE_WINDOW_H
#define VULKAN_LVE_WINDOW_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include "vulkan/vulkan.h"
#include <string>
#include <utility>

namespace lve {
    class LveWindow {
    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();

        LveWindow(const LveWindow &)= delete;
        LveWindow &operator=(const LveWindow &)= delete;

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        bool shouldClose();

    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *wwindow{};
    };
}
#endif //VULKAN_LVE_WINDOW_H
