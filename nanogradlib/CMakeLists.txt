cmake_minimum_required(VERSION 3.11-3.18)

project(nanogradlib)

add_library(nanogradlib src/value.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(nanogradlib PUBLIC cxx_std_20)
