cmake_minimum_required(VERSION 3.1.0)

add_compile_options(-std=c++11)

add_executable(dhcp_server "src/dhcp_server.cpp")

include_directories("include")

target_link_libraries(dhcp_server PUBLIC "-lpthread")

add_executable(dhcp_server_ext "src/dhcp_server_ext.cpp")

include_directories("include")

target_link_libraries(dhcp_server_ext PUBLIC "-lpthread")
