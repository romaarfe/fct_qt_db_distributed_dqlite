# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/projetoDqlite_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/projetoDqlite_autogen.dir/ParseCache.txt"
  "projetoDqlite_autogen"
  )
endif()
