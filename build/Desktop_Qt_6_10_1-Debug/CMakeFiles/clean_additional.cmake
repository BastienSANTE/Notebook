# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Notebook_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Notebook_autogen.dir/ParseCache.txt"
  "Notebook_autogen"
  "_deps/jkqtplotter-build/lib/jkqtcommon/CMakeFiles/JKQTCommon6_autogen.dir/AutogenUsed.txt"
  "_deps/jkqtplotter-build/lib/jkqtcommon/CMakeFiles/JKQTCommon6_autogen.dir/ParseCache.txt"
  "_deps/jkqtplotter-build/lib/jkqtcommon/JKQTCommon6_autogen"
  "_deps/jkqtplotter-build/lib/jkqtfastplotter/CMakeFiles/JKQTFastPlotter6_autogen.dir/AutogenUsed.txt"
  "_deps/jkqtplotter-build/lib/jkqtfastplotter/CMakeFiles/JKQTFastPlotter6_autogen.dir/ParseCache.txt"
  "_deps/jkqtplotter-build/lib/jkqtfastplotter/JKQTFastPlotter6_autogen"
  "_deps/jkqtplotter-build/lib/jkqtmath/CMakeFiles/JKQTMath6_autogen.dir/AutogenUsed.txt"
  "_deps/jkqtplotter-build/lib/jkqtmath/CMakeFiles/JKQTMath6_autogen.dir/ParseCache.txt"
  "_deps/jkqtplotter-build/lib/jkqtmath/JKQTMath6_autogen"
  "_deps/jkqtplotter-build/lib/jkqtmathtext/CMakeFiles/JKQTMathText6_autogen.dir/AutogenUsed.txt"
  "_deps/jkqtplotter-build/lib/jkqtmathtext/CMakeFiles/JKQTMathText6_autogen.dir/ParseCache.txt"
  "_deps/jkqtplotter-build/lib/jkqtmathtext/JKQTMathText6_autogen"
  "_deps/jkqtplotter-build/lib/jkqtplotter/CMakeFiles/JKQTPlotter6_autogen.dir/AutogenUsed.txt"
  "_deps/jkqtplotter-build/lib/jkqtplotter/CMakeFiles/JKQTPlotter6_autogen.dir/ParseCache.txt"
  "_deps/jkqtplotter-build/lib/jkqtplotter/JKQTPlotter6_autogen"
  )
endif()
