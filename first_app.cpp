//
// Created by andre on 18/07/2024.
//

#include "first_app.h"

namespace lve {
    void FirstApp::run() {
        while(!lveWindow.shouldClose()){
            glfwPollEvents();
        }
    }
} // lve