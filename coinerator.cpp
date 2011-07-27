#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include "includes/json/json.h"

using namespace std;

void jsonReadTickerData()
{
    // Read the json data
    ifstream jsondata("json.output");
    string data = "";
        if(jsondata.is_open())
        {
            while(jsondata.good())
            {
                getline(jsondata, data);
            }
            jsondata.close();
        }
    // Parse the result
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(data, root);
    if(!parsingSuccessful)
        cout << "failed to parse data" << endl;
    else
        cout << root.get("encoding", "UTF-8").asString() << endl;
}

void getTickerData()
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    FILE* out = fopen("json.output","w");

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://mtgox.com/api/0/data/ticker.php");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, out);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_REFERER, "https://mtgox.com");
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(out);
}

int main(void)
{
    // get ticker data
    getTickerData();    
    jsonReadTickerData();
    return 0;
}
