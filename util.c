#include "util.h"

size_t writeMemoryCallback(void* contents,size_t size,size_t nmemb,void* userp){
	size_t realsize= size* nmemb;
	fwrite(contents,size,nmemb,stdout);
	return realsize;
}