# Install script for directory: C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtfastplotter

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Notebook")
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

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1310_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/libJKQTFastPlotter6_Debug.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/output/libJKQTFastPlotter6_Debug.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTFastPlotter6_Debug.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTFastPlotter6_Debug.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1310_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTFastPlotter6_Debug.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtfastplotter" TYPE FILE FILES
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtfastplotter/jkqtfastplotter_imexport.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtfastplotter/jkqtfastplotter.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTFastPlotter6Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTFastPlotter6Targets.cmake"
         "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTFastPlotter6Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTFastPlotter6Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTFastPlotter6Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTFastPlotter6Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTFastPlotter6Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/JKQTFastPlotter6Version.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/JKQTFastPlotter6Config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/JKQTPlotter" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtfastplotter/JKQTFastPlotter6_Readme.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/JKQTPlotter" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/LICENSE")
endif()

