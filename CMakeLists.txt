cmake_minimum_required (VERSION 2.6)
project (LoLFeeder)

set (LOLFEEDER_VERSION_MAJOR 0)
set (LOLFEEDER_VERSION_MINOR 5)
set (LOLFEEDER_VERSION_PATCH 0)
set (LOLFEEDER_VERSION_EXTRA 0)
set (LOLFEEDER_VERSION "${LOLFEEDER_VERSION_MAJOR}.${LOLFEEDER_VERSION_MINOR}")
set (LOLFEEDER_VERSION_FULL "${LOLFEEDER_VERSION}_${LOLFEEDER_VERSION_PATCH}")
set (CMAKE_BUILD_TYPE Debug)
if(MSVC)
  set (CMAKE_CXX_FLAGS_DEBUG "/D_CRT_SECURE_NO_WARNINGS")
else()
  set (CMAKE_CXX_FLAGS_DEBUG "-std=c++11")
endif()
add_subdirectory(curlcpp)
include_directories ("${PROJECT_BINARY_DIR}")
add_executable (lolfeeder main.cpp)
target_link_libraries (lolfeeder jsoncpp curlcpp)