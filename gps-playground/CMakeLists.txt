cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(gps-playground LANGUAGES C VERSION 1.0.0)

# we need to be able to include generated header files
zephyr_library_include_directories(${CMAKE_CURRENT_BINARY_DIR})

# add target sources to existing zephyr library
target_sources(app PRIVATE
    src/main.c
)
