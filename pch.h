#ifndef PCH_H
#define PCH_H

#include "framework.h"

#define CURL_STATICLIB
#include "curl/curl.h"

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

#include "curl/json.hpp"
using namespace nlohmann;

#include "offsets.hpp"
#include "getoffsets.hpp"

#endif //PCH_H
