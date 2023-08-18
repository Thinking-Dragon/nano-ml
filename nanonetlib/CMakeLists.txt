cmake_minimum_required(VERSION 3.11-3.18)

project(nanonetlib)

add_library(
    nanonetlib
    src/neural_module.cpp
    src/neuron.cpp
    src/layer.cpp
    src/multi_layer_perceptron.cpp
)

target_link_libraries(nanonetlib PRIVATE nanogradlib)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(nanonetlib PUBLIC cxx_std_20)
