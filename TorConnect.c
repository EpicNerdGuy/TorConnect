#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc,char* argv[]){
	curl_global_init(CURL_GLOBAL_DEFAULT);
	CURLcode ret;
	CURL *curl= curl_easy_init();
	if(argc!=3){
		printf("Usage: Torconnect curl <URL>\n");
		return 1;
	}
	if(curl){
		curl_easy_setopt(curl,CURLOPT_URL,argv[2]);
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writeMemoryCallback);
		curl_easy_setopt(curl,CURLOPT_PROXY,"127.0.0.1:9050");
		curl_easy_setopt(curl,CURLOPT_PROXYTYPE,CURLPROXY_SOCKS5_HOSTNAME);
		ret = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return 0;
}