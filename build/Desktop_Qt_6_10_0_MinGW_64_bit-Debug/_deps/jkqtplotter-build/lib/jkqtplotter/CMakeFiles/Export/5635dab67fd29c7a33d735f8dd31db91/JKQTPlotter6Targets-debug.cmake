#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JKQTPlotter6::JKQTPlotter6" for configuration "Debug"
set_property(TARGET JKQTPlotter6::JKQTPlotter6 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(JKQTPlotter6::JKQTPlotter6 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libJKQTPlotter6_Debug.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libJKQTPlotter6_Debug.dll"
  )

list(APPEND _cmake_import_check_targets JKQTPlotter6::JKQTPlotter6 )
list(APPEND _cmake_import_check_files_for_JKQTPlotter6::JKQTPlotter6 "${_IMPORT_PREFIX}/lib/libJKQTPlotter6_Debug.dll.a" "${_IMPORT_PREFIX}/bin/libJKQTPlotter6_Debug.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
