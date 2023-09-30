add_library(FileDownloader_Controller STATIC 
	"fdownload/Controller.cpp"
	"fdownload/Controller.hpp"
)

set_target_properties(FileDownloader_Controller PROPERTIES CXX_STANDARD 20)

target_link_libraries(FileDownloader_Controller FileDownloader_Common)

target_include_directories(FileDownloader_Controller INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

