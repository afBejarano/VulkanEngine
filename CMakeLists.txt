cmake_minimum_required(VERSION 3.28)
project(Vulkan)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vulkan main.cpp
        lve_window.h
        lve_window.cpp
        first_app.cpp
        first_app.h
        lve_pipeline.cpp
        lve_pipeline.h
        lve_device.cpp
        lve_device.h)

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC "C:/VulkanSDK/1.2.189.2/Include")
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)