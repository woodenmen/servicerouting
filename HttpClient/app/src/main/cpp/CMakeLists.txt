# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


add_library(native-lib SHARED
                       src/native-lib.cpp
                       src/dhcp_client.cpp
                       src/server_client.cpp)

include_directories("include")

target_link_libraries(native-lib log)