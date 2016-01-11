# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
cmake_minimum_required (VERSION 2.8)
project (black-mamba-engine)


# ┌──────────────────────────────────────────────────────────────────┐
# │  Variable pool                                                   │
# └──────────────────────────────────────────────────────────────────┘
set(GLFW_SOURCE_DIR "lib/glfw")
set(GLM_SOURCE_DIR "lib/glm")
set(GLEW_SOURCE_DIR "lib/glew")


# ┌──────────────────────────────────────────────────────────────────┐
# │  Compilation flags                                               │
# └──────────────────────────────────────────────────────────────────┘
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

# Turn on all warnings
add_definitions(-Wall)


# ┌──────────────────────────────────────────────────────────────────┐
# │  Load libraries                                                  │
# └──────────────────────────────────────────────────────────────────┘
# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE STRING "" FORCE)
add_subdirectory(${GLFW_SOURCE_DIR})
include_directories(${GLFW_SOURCE_DIR}/include)

# glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED "" OFF)
add_subdirectory(${GLEW_SOURCE_DIR})
include_directories(${GLEW_SOURCE_DIR}/include ${GLEW_SOURCE_DIR}/glew/src)

# glm
include_directories(${GLM_SOURCE_DIR})

# ┌──────────────────────────────────────────────────────────────────┐
# │  Build executable                                                │
# └──────────────────────────────────────────────────────────────────┘
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
add_executable(main ${source_files})
target_link_libraries(main glfw ${GLFW_LIBRARIES} libglew_static)