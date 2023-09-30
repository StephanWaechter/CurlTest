add_executable (FileDownloaderCmdline FileDownloaderCmdline.cpp)
set_property(TARGET FileDownloaderCmdline PROPERTY CXX_STANDARD 20)

find_package(CURL REQUIRED)

target_link_libraries(FileDownloaderCmdline PRIVATE 
	FileDownloader_Model CURL::libcurl)
