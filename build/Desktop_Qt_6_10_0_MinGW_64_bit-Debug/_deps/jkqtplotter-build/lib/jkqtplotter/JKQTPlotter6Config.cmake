# Package-config file for JKQTPlotter library
#   (part of JKQtPlotter, version 5.0.0)
#
# see: https://github.com/jkriege2/JKQtPlotter
# Copyright: (c) Jan Krieger <jan@jkrieger.de>
#

# package requires Qt 6
find_package(Qt6 COMPONENTS Core Gui Widgets Svg Xml OpenGL PrintSupport REQUIRED)
find_package(JKQTCommon6 REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_MODULE_PATH})
find_package(JKQTMath6 REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_MODULE_PATH})
find_package(JKQTMathText6 REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_MODULE_PATH})

# include auto-generated targets.cmake file
include("${CMAKE_CURRENT_LIST_DIR}/JKQTPlotter6Targets.cmake")


if(NOT TARGET JKQTPlotter::JKQTPlotter)
  add_library(JKQTPlotter::JKQTPlotter ALIAS JKQTPlotter6::JKQTPlotter6)
endif()
