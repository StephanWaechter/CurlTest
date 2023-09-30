#include "Downloader.hpp"
#include <curl/curl.h>
#include <stdexcept>

namespace fdownload
{
	static void CURL_throw(CURLcode rc)
	{
		if (rc != CURLE_OK)
		{
			throw std::runtime_error(curl_easy_strerror(rc));
		}
	}

	static CURL* CURL_init()
	{
		CURL* curl = curl_easy_init();
		if (curl == nullptr)
		{
			throw std::runtime_error("curl_easy_init returned nullptr");
		}
		return curl;
	};

	void Downloader::CURL_deleter::operator()(CURL* curl_ptr) const
	{
		curl_easy_cleanup(curl_ptr);
	}

	Downloader::Downloader(std::string const& url)
		: m_curl{ std::unique_ptr<CURL, CURL_deleter>(CURL_init()) }
	{
		CURLcode rc = curl_easy_setopt(
			m_curl.get(),
			CURLOPT_URL,
			url.c_str()
		);
		CURL_throw(rc);
	}

	void Downloader::set_buffersize(std::size_t size)
	{
		CURLcode rc = curl_easy_setopt(
			m_curl.get(),
			CURLOPT_BUFFERSIZE,
			size
		);
		CURL_throw(rc);
	}

	void Downloader::set_callback(callback_function callback)
	{
		CURLcode rc;
		m_callback = callback;
		rc = curl_easy_setopt(
			m_curl.get(),
			CURLOPT_WRITEFUNCTION,
			writecallback
		);
		CURL_throw(rc);

		rc = curl_easy_setopt(
			m_curl.get(),
			CURLOPT_WRITEDATA, this);
		CURL_throw(rc);
	}

	void Downloader::preform()
	{
		auto rc = curl_easy_perform(m_curl.get());
		CURL_throw(rc);
	}

	size_t Downloader::writecallback(char* content, size_t size, size_t nmemb, void* userp)
	{
		auto downloader = static_cast<Downloader*>(userp);
		std::span<char> data(content, size * nmemb);
		return downloader->m_callback(data);
	}
}