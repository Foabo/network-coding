# Install script for directory: /Users/inf/CLionProjects/network-coding

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/lib/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c4/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c5-tcp/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c6-udp/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c7-ipc/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c11-conn-close/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c12-keepalive/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c13-batchwrite/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c14-udpconn/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c15-address-used/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c16-stream/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c17-reliable/cmake_install.cmake")
  include("/Users/inf/CLionProjects/network-coding/cmake-build-debug/c18-cmd/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/inf/CLionProjects/network-coding/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
