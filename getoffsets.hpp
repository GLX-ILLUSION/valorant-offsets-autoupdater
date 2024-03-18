#pragma once

class getoffsets
{
private:
	std::string fetch_data_from_url(const std::string& url, struct curl_slist* headers);
	json get();
	template <typename T> void ReadJson(const json& src, T& dest);
public:
	void initialize();
};

