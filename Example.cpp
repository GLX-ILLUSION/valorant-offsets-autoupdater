#include "offsets.hpp"
#pragma comment(lib,"urlmon.lib) //for urldownload

int main(int argc, char** argv)
{

	const char* url = (argc > 1 ? argv[1] : "https://raw.githubusercontent.com/GLX-ILLUSION/offsets/main/offsets.json");
	HRESULT result = URLDownloadToFileA(nullptr, url, "offsets.json", 0, nullptr);
	if (result != S_OK)
	{
		std::cout << ("[!] Could not update offsets.") << std::endl;

		//you can implement another method to get offsets if get problems with github link
	}

	offsets::initialize();
}
