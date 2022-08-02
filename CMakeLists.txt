cmake_minimum_required(VERSION 3.0.2)

option(PARALLEL "Enable cuda parallelism" OFF)

project(Handy_OBJ)

SET(VERBOSE OFF)

# Compilation options
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OBJ_COMPILER CMAKE_CXX_COMPILER)

if(VERBOSE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Header files
include_directories(include OpenGL_libs/include)

# Adding source files
SET( SRC
    src/main.cpp src/controls.cpp src/shader.cpp src/texture.cpp
)

add_executable(exec ${SRC})

# the GL libs family
find_package(OpenGL REQUIRED)


# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(Error " GLEW not found")
endif(NOT GLEW_FOUND)

# GLFW
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
add_definitions(${GLFW_DEFINITIONS})
if(NOT GLFW_FOUND)
    message(Error "GLFW not found")
endif(NOT GLFW_FOUND)

# Detect and add libs et al.
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

target_sources(exec PRIVATE ${SRC})

target_include_directories(exec PRIVATE
                            include
                            OpenGL_libs/include
                            ${OPENGL_INCLUDE_DIRS} 
                            ${GLEW_INCLUDE_DIRS})

target_link_libraries(exec PRIVATE
                    ${OPENGL_LIBRARIES} 
                    ${GLUT_LIBRARY}
                    ${GLEW_LIBRARIES} 
                    glfw)