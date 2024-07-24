//
// Created by andre on 18/07/2024.
//

#ifndef VULKAN_LVE_PIPELINE_H
#define VULKAN_LVE_PIPELINE_H

#include "lve_device.h"

namespace lve {
    struct PipelineConfigInfo {

    };

    class LvePipeline {
    public:
        LvePipeline(LveDevice &device, const std::string &vertFilePath, const std::string &fragFilePath,
                    const PipelineConfigInfo &configInfo);

        ~LvePipeline();

        LvePipeline(const LvePipeline &) = delete;

        LvePipeline operator=(const LvePipeline &) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:

        LveDevice &lveDevice;
        VkPipeline pipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

        static std::vector<char> readFile(const std::string &filepath);

        void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath,
                                    const PipelineConfigInfo &configInfo);

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);
    };

} // lve

#endif //VULKAN_LVE_PIPELINE_H
