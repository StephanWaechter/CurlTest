# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("FileDownloader")

set(COMPILER_WARNINGS 
    -Wall)

# Include sub-projects.
add_subdirectory ("Controller")
add_subdirectory ("View")
add_subdirectory ("Model")
add_subdirectory ("Common")
add_subdirectory ("FileDownloader")
add_subdirectory ("FileDownloaderCmdline")
