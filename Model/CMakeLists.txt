add_library (FileDownloader_Model STATIC
	"fdownload/Downloader.cpp"
	"fdownload/Downloader.hpp")
set_property(TARGET FileDownloader_Model PROPERTY CXX_STANDARD 20)

find_package(CURL CONFIG REQUIRED)

target_link_libraries(FileDownloader_Model PRIVATE CURL::libcurl)
target_compile_options(FileDownloader_Model PRIVATE "${COMPILER_WARNINGS}")

target_include_directories(FileDownloader_Model INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)