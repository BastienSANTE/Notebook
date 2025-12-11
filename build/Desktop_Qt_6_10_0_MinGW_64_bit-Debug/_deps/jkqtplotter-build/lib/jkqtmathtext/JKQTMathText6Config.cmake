# Package-config file for JKQTMathText library
#   (part of JKQtPlotter, version 5.0.0)
#
# see: https://github.com/jkriege2/JKQtPlotter
# Copyright: (c) Jan Krieger <jan@jkrieger.de>
#


# package requires Qt 5/6
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

find_package(JKQTCommon6 REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_MODULE_PATH})

# include auto-generated targets.cmake file
include("${CMAKE_CURRENT_LIST_DIR}/JKQTMathText6Targets.cmake")


if(NOT TARGET JKQTPlotter::JKQTMathText)
  add_library(JKQTPlotter::JKQTMathText ALIAS JKQTPlotter6::JKQTMathText6)
endif()
