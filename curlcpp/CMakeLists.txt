cmake_minimum_required (VERSION 2.8)
project (curlcpp)
#code to check if libcurl is installed
set(sources_dir "${curlcpp_SOURCE_DIR}/src")
set(headers_dir "${curlcpp_SOURCE_DIR}/include")
include_directories (sources_dir)
include_directories (headers_dir)
set(sources ${sources_dir}/curl_easy.cpp 
	    ${sources_dir}/curl_header.cpp
	    ${sources_dir}/curl_http_post.cpp 
	    ${sources_dir}/curl_interface.cpp 
	    ${sources_dir}/curl_message.cpp 
	    ${sources_dir}/curl_multi.cpp) 
if(NOT MSVC)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()
add_library (curlcpp STATIC ${sources}) 
target_link_libraries (curlcpp curl)