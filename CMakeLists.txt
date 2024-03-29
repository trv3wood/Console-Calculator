cmake_minimum_required(VERSION 3.0.0)

project(high-precision-float VERSION 0.1.0 LANGUAGES CXX)

if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
   message(WARNING "The binary directory of CMake cannot be the same as source directory!")
endif()

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

if(WIN32)
   add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if (NOT MSVC)
   find_program(CCACHE_PROGRAM ccache)
   if(CCACHE_PROGRAM)
      message(STATUS "found CCache: ${CCACHE_PROGRAM}")
      set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
      set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
   endif()
endif()

enable_testing()

include_directories(include)
aux_source_directory(src/ClassFloat FLOATSRCS)
add_library(Float OBJECT ${FLOATSRCS})

set(isDebugMode OFF)
if(isDebugMode) #编译测试程序
   find_package(GTest REQUIRED)
   find_package(Threads REQUIRED)

   add_executable(HPFtests tests/g-test.cpp) 
   target_link_libraries(HPFtests Float)
   target_link_libraries(HPFtests ${GTEST_BOTH_LIBRARIES})
   target_link_libraries(HPFtests ${CMAKE_THREAD_LIBS_INIT})

   add_test(Tests HPFtests)
else() #编译发布版本
   add_executable(${PROJECT_NAME} src/main.cpp)
   target_link_libraries(${PROJECT_NAME} Float)

   aux_source_directory(src/console CONSOLESRCS)
   add_library(console OBJECT ${CONSOLESRCS})
   target_link_libraries(console Float)

   target_link_libraries(${PROJECT_NAME} console)
endif(isDebugMode)