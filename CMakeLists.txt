# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
cmake_minimum_required (VERSION 2.8)
project (black-mamba)
set(GLFW_SOURCE_DIR "lib/glfw")
set(GLM_SOURCE_DIR "lib/glm")
set(GLEW_SOURCE_DIR "lib/glew")

# ┌──────────────────────────────────────────────────────────────────┐
# │  Compilation flags                                               │
# └──────────────────────────────────────────────────────────────────┘
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
add_definitions(-Wall)


# ┌──────────────────────────────────────────────────────────────────┐
# │  Load libraries                                                  │
# └──────────────────────────────────────────────────────────────────┘
# glfw
#set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE STRING "" FORCE)
set(GLFW_INSTALL OFF CACHE STRING "" FORCE)
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
add_subdirectory(${GLFW_SOURCE_DIR})
include_directories(${GLFW_SOURCE_DIR}/include)

# add libs
#add_library(glew STATIC
#  ${GLEW_SOURCE_DIR}/src/glew.c
#  ${GLEW_SOURCE_DIR}/include
#)

# glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED "" OFF)
add_subdirectory(${GLEW_SOURCE_DIR})
include_directories(${GLEW_SOURCE_DIR}/include ${GLEW_SOURCE_DIR}/src)

# glm
include_directories(${GLM_SOURCE_DIR})


# ┌──────────────────────────────────────────────────────────────────┐
# │  Build executable                                                │
# └──────────────────────────────────────────────────────────────────┘
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
add_executable(main ${source_files})
target_link_libraries(main glfw ${GLFW_LIBRARIES} libglew_static)


# ┌──────────────────────────────────────────────────────────────────┐
# │  POST build                                                      │
# └──────────────────────────────────────────────────────────────────┘
add_custom_target(run
    COMMAND open main && quit
)



# TO IMPLEMENT
#if (APPLE)
#  set(APP_NAME "OpenGL Boilerplate")

  # if (EXISTS icon.icns)
#    add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp icon.icns)
#    set_source_files_properties("icon.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
  # else ()
    # add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp)
  # endif ()

 # target_link_libraries(${APP_NAME} glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} glew)
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE "icon.icns")

  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME ${APP_NAME})
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_STRING "OpenGL boilerplate example app")
#endif()
