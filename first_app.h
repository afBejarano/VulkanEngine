//
// Created by andre on 18/07/2024.
//

#ifndef VULKAN_FIRST_APP_H
#define VULKAN_FIRST_APP_H

#include "lve_pipeline.h"

namespace lve {

    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "First App"};
        LveDevice device = LveDevice{lveWindow};
        LvePipeline lvePipeline{device, "shaders/Shader.vert.spv", "shaders/Shader.frag.spv",
                                LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };

} // lve

#endif //VULKAN_FIRST_APP_H
