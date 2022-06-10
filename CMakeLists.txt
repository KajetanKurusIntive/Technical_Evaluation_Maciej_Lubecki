cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# in case of problems with building without build.sh: 
# PATH_TO_VCPKG_DIRECTORY has to be absolute because EXISTS doesn't recognize ~ and such (at least on my 3.10 version)
if (EXISTS ${PATH_TO_VCPKG_DIRECTORY})
        set(USING_VCPKG TRUE)
        message("VCPKG directory specified, will compile with tests.")
else()
        set(USING_VCPKG FALSE)
        message("VCPKG directory not set, compiling without tests.")
endif()

# vcpkg config
if (${USING_VCPKG})        
        set(CMAKE_TOOLCHAIN_FILE "${PATH_TO_VCPKG_DIRECTORY}/scripts/buildsystems/vcpkg.cmake")
endif()

project(mlubecki)

# main library
set(MAIN_LIBRARY_NAME main_lib)
include_directories(${CMAKE_SOURCE_DIR}/src/)
link_directories(${CMAKE_SOURCE_DIR}/src/)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/)

# compiler flags
set(CMAKE_CXX_FLAGS "-std=c++14 -O2 ${CMAKE_CXX_FLAGS}")

# main executable target options
set(TARGET_NAME animals.out)
add_executable(${TARGET_NAME} src/Main.cpp)
target_link_libraries (${TARGET_NAME} ${MAIN_LIBRARY_NAME})

set_target_properties(
        ${TARGET_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#tests
if (${USING_VCPKG})
        add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
endif()
