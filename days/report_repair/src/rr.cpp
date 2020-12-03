/* Day 1 of Advent of code challenge 1 by PJG */
#include <iostream>
#include "get_cookie.h"

#include <cstdio>
#include <cstring>
#include <cstdio>
#include <curl/curl.h>
using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(void)
{
    const char *data_url = "https://adventofcode.com/2020/day/1/input";
    const char *data_path = "data_raw/day1";

    CURL *curl;
    FILE *fp;
    CURLcode res;



    curl = curl_easy_init();
    if (curl) {
        fp = fopen(data_path,"wb");

        /* Setup the https:// verification options. Note we   */
        /* do this on all requests as there may be a redirect */
        /* from http to https and we still want to verify     */
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_URL, data_url);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "./ca-bundle.crt");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        int i=fclose(fp);
    }
    return 0;
}