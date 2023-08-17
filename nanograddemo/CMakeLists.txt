cmake_minimum_required(VERSION 3.11-3.18)

project(nanograddemo)

add_executable(nanograd_demo src/main.cpp)

target_link_libraries(nanograd_demo PRIVATE nanogradlib)
target_compile_features(nanograd_demo PUBLIC cxx_std_20)
