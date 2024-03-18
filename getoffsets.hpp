#pragma once

class getoffsets
{
private:
	size_t call_back(const char* in, size_t size, size_t num, std::string* out);
	std::string fetch_data_from_url(const std::string& url, struct curl_slist* headers);
	json get();
	template <typename T> void ReadJson(const json& src, T& dest);
public:
	void initialize();
};

