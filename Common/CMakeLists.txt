add_library(FileDownloader_Common INTERFACE 
	swaechter/Observable.hpp
	argparse/argparse.hpp)
set_property(TARGET FileDownloader_Common PROPERTY CXX_STANDARD 20)

target_include_directories(FileDownloader_Common INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

find_package(PkgConfig)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0 )

target_include_directories(FileDownloader_Common SYSTEM INTERFACE ${GTKMM_INCLUDE_DIRS})