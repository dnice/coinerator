#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

void getTickerData()
{
    CURL *curl;
    CURLcode res;

    // output file
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://mtgox.com/api/0/data/ticker.php");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_REFERER, "https://mtgox.com");
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        res = curl_easy_perform(curl);
        cout << "done" << endl;
        curl_easy_cleanup(curl);
    }
}

int main(void)
{
    // get ticker data
    getTickerData();    
    return 0;
}
