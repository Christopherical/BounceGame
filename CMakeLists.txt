cmake_minimum_required(VERSION 3.28)
project(BounceGame2 VERSION 1.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(sfml GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.2)
FetchContent_MakeAvailable(sfml)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(BounceGame2 ${SOURCES})

target_include_directories(BounceGame2 PRIVATE include)
target_compile_features(BounceGame2 PRIVATE cxx_std_20)
target_link_libraries(BounceGame2 PRIVATE SFML::Graphics SFML::Audio)
