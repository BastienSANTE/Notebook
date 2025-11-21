# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NoteBook_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NoteBook_autogen.dir\\ParseCache.txt"
  "NoteBook_autogen"
  )
endif()
