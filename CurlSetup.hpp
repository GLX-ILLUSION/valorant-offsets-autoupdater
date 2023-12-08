

#include <"json.hpp">
#include <string>
#include <vector>


#define CURL_STATICLIB
#include <curl.h>

#ifdef _DEBUG
#pragma comment(lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment(lib, "curl/libcurl_a.lib")
#endif

#pragma comment(lib,"Normaliz.lib")
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"Wldap32.lib")
#pragma comment(lib,"Crypt32.lib")
#pragma comment(lib,"advapi32.lib")

size_t call_back(const char* in, size_t size, size_t num, std::string* out)
{
	const size_t totalBytes(size * num);
	out->append(in, totalBytes);
	return totalBytes;
}

std::string fetch_data_from_url(const std::string& url, struct curl_slist* headers = NULL)
{
	CURL* curl = curl_easy_init();
	std::string response_string;

	if (!curl)
	{
		throw std::runtime_error(obsSecureString("Failed to initialize curl."));
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, call_back);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
	if (headers)
	{
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	}

	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	if (res != CURLE_OK)
	{
		throw std::runtime_error(obsSecureString("Failed to fetch data from URL."));
	}

	return response_string;
}

json setup_curl()
{
	struct curl_slist* headers = NULL;
	auto responseData = fetch_data_from_url(obsSecureString("https://raw.githubusercontent.com/GLX-ILLUSION/valorant-offsets-autoupdater/main/offsets.json"), headers);
	curl_slist_free_all(headers);

	return json::parse(responseData);
}
