#include <fdownload/Downloader.hpp>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <curl/curl.h>

using namespace fdownload;
int main(int argc, char** argv)
{
	try
	{
		bool first = true;
		std::ofstream file{ "test.mp4", std::ios_base::binary | std::ios_base::out };
		auto copy = [&](std::span<char> chunk)->size_t
		{
			file.write(chunk.data(), chunk.size());
			std::cout << ".";
			return chunk.size();
		};

		Downloader download("http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/ElephantsDream.mp4");
		download.set_callback(copy);
		std::cout << "downloading: ";
		download.preform();
		std::cout << " done\n";
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}