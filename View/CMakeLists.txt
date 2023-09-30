add_library(FileDownloader_View STATIC
	"fdownload/MainWindow.cpp"
	"fdownload/MainWindow.hpp"
)
set_property(TARGET FileDownloader_View PROPERTY CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0 )

target_include_directories(FileDownloader_View SYSTEM PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(FileDownloader_View ${GTKMM_LINK_LIBRARIES} FileDownloader_Controller)

target_include_directories(FileDownloader_View INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)
