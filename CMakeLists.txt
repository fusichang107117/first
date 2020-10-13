cmake_minimum_required(VERSION 3.10)

project(first)

MESSAGE(STATUS "Hello This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "Hello This is SOURCE dir " ${PROJECT_SOURCE_DIR})

enable_testing()


add_subdirectory(src)


#enable_testing()







