//
// Created by andre on 18/07/2024.
//

#include "lve_pipeline.h"

//std
#include <fstream>

namespace lve {

    LvePipeline::LvePipeline(LveDevice &device, const std::string &vertFilePath, const std::string &fragFilePath,
                             const PipelineConfigInfo &configInfo) : lveDevice(device) {
        createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
    }

    std::vector<char> LvePipeline::readFile(const std::string &filepath) {

        std::ifstream file(filepath, std::ios::ate | std::ios::binary);

        if (!file.is_open())
            throw std::runtime_error("failed to open file: " + filepath);

        std::streamsize fileSize = static_cast<std::streamsize>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath,
                                             const PipelineConfigInfo& configInfo) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex code size: " << vertCode.size() << '\n';
        std::cout << "Fragment code size: " << fragCode.size() << '\n';
    }

    void LvePipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule) {
        VkShaderModuleCreateInfo createInfo{};

        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
        createInfo.pNext = nullptr;

        if(vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS){
            throw std::runtime_error("Could not create shader module");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }

    LvePipeline::~LvePipeline() = default;


} // lve