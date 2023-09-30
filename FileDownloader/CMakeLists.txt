add_executable (FileDownloader FileDownloader.cpp)
set_property(TARGET FileDownloader PROPERTY CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

target_include_directories(FileDownloader SYSTEM PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(FileDownloader ${GTKMM_LINK_LIBRARIES} FileDownloader_View FileDownloader_Controller)

target_compile_definitions(FileDownloader PRIVATE
	GTK_APPLICATION_NAME="com.sw.download_manager"
)