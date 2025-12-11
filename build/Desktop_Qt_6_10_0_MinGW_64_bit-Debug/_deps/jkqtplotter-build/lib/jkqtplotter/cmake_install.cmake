# Install script for directory: C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/graphs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/gui/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/libJKQTPlotter6_Debug.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/output/libJKQTPlotter6_Debug.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTPlotter6_Debug.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTPlotter6_Debug.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Qt/Tools/mingw1310_64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libJKQTPlotter6_Debug.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter" TYPE FILE FILES
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtptools.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpbaseelements.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpbaseplotter.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpdatastorage.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpgraphsbase.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpgraphsbaseerrors.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpgraphsbasestylingmixins.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtplotter.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtplotterstyle.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpkeystyle.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpkey.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpbaseplotterstyle.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpcoordinateaxes.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpcoordinateaxesstyle.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpimagetools.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtpgraphsbasestyle.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtplotter_configmacros.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/jkqtplotter_imexport.h"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter/graphs" TYPE FILE FILES
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpboxplot.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpboxplotbase.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpboxplotstylingmixins.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpevaluatedfunctionbase.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpevaluatedfunction.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpfilledcurve.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpfinancial.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgeometric.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgeoannotations.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgeobase.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgeolines.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgeoshapes.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpimage.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpimpulses.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpparsedfunction.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtppeakstream.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpsinglecolumnsymbols.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpimageoverlays.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpcontour.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpimagergb.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpviolinplot.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpviolinplotstylingmixins.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpstatisticsadaptors.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpscatter.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtprange.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpspecialline.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpbarchartbase.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpbarchart.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpevaluatedparametriccurve.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtplines.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgraphlabelstylemixin.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpgraphlabels.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/graphs/jkqtpvectorfield.h"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/jkqtplotter/gui" TYPE FILE FILES
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/gui/jkqtpcomboboxes.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/gui/jkqtpenhancedspinboxes.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/gui/jkqtpenhancedtableview.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/gui/jkqtpgraphsmodel.h"
    "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/lib/jkqtplotter/gui/jkvanishqtoolbar.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTPlotter6Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTPlotter6Targets.cmake"
         "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTPlotter6Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTPlotter6Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6/JKQTPlotter6Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTPlotter6Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/CMakeFiles/Export/5635dab67fd29c7a33d735f8dd31db91/JKQTPlotter6Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/JKQTPlotter6Version.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JKQTPlotter6" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/JKQTPlotter6Config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/JKQTPlotter" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-build/lib/jkqtplotter/JKQTPlotter6_Readme.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/JKQTPlotter" TYPE FILE FILES "C:/Users/b.sante/Desktop/LocalRepo/Notebook/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/_deps/jkqtplotter-src/LICENSE")
endif()

