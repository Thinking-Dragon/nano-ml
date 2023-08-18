cmake_minimum_required(VERSION 3.11-3.18)

project(nanonetdemo)

add_executable(nanonet_demo src/main.cpp)

target_link_libraries(nanonet_demo PRIVATE nanogradlib)
target_link_libraries(nanonet_demo PRIVATE nanonetlib)
target_compile_features(nanonet_demo PUBLIC cxx_std_20)
