cmake_minimum_required(VERSION 3.1.0)

add_compile_options(-std=c++11)

add_executable(dhcp_client "src/dhcp_client.cpp")

include_directories("include")

target_link_libraries(dhcp_client PUBLIC "-lpthread")