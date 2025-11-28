cmake_minimum_required(VERSION 3.28)
project(BounceGame CXX)

include(FetchContent)
FetchContent_Declare(sfml GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.2)
FetchContent_MakeAvailable(sfml)

add_executable (BounceGame "main.cpp")
target_compile_features(BounceGame PRIVATE cxx_std_20)
target_link_libraries(BounceGame PRIVATE SFML::Graphics)