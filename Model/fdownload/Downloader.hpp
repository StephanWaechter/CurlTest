#pragma once
#include <memory>
#include <string>
#include <span>
#include <functional>

using CURL = void;
namespace fdownload
{
	class Downloader
	{
	public:
		using callback_function = std::function<size_t(std::span<char> data)>;
		Downloader(
			std::string const& url);

		Downloader(Downloader const& copy) = delete;
		Downloader& operator=(Downloader const& copy) = delete;
		Downloader(Downloader&& move) = delete;

		void set_buffersize(std::size_t size);
		void set_callback(callback_function callback);
		void preform();

	private:
		struct CURL_deleter { CURL operator() (CURL* curl_ptr) const; };
		std::unique_ptr<CURL, CURL_deleter> m_curl;
		static size_t writecallback(char* content, size_t size, size_t nmemb, void* userp);
		callback_function m_callback{ nullptr };
	};
};