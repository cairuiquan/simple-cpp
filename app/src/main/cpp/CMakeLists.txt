# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#set(GLOBAL_CXX_FLAGS " \
#    -std=c++11 \
#    -fPIC \
#    -Wall \
#    -Wno-unused \
#    -Wno-unused-parameter \
#    -Wno-sign-compare \
#    -fcolor-diagnostics \
#    -Wno-unused-command-line-argument \
#    ")

#set(CMAKE_CXX_FLAGS ${GLOBAL_CXX_FLAGS})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library( # Sets the name of the library.
             mylib
             # Sets the library as a shared library.
             SHARED
             # Provides a relative path to your source file(s).
        SimpleCppJNI.cpp
        JniUtils.cpp)

# Standard Android dependencies
find_library(android-lib android)
#find_library(GLESv2-lib GLESv2)
#find_library(GLESv3-lib GLESv3)
find_library(log-lib log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(mylib
        ${android-lib}
#        ${GLESv2-lib}
#        ${GLESv3-lib}
        ${log-lib} )