//
// Created by andre on 18/07/2024.
//
#include <stdexcept>
#include "lve_window.h"

namespace lve {

    LveWindow::LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(std::move(name)) {
        initWindow();
    }

    LveWindow::~LveWindow() {
        glfwDestroyWindow(wwindow);
        glfwTerminate();
    }

    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        wwindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    bool LveWindow::shouldClose() {
        return glfwWindowShouldClose(wwindow);
    }

    void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, wwindow, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface");
        }
    }
}