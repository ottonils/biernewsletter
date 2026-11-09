#include <iostream>
#include <curl/curl.h>

using namespace std;

int main() 
{
    CURL *curl = curl_easy_init();

    if (curl == nullptr)
    {
        cerr << "Failed to initialize CURL" << endl;
        return 1;
    }

    cout << "CURL initialized successfully" << endl;

    curl_easy_setopt(
        curl, 
        CURLOPT_URL, "https://api.api.sh/rewe/v1/offers?market=8548598"
    );

    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 120L);

    struct curl_slist* headers = nullptr;

    headers = curl_slist_append(
        headers,
        "x-api-key: ash_live_X2RV2CcsiDDieFDWf8498GUBB8mE3f5U"
    );

    curl_easy_setopt(
        curl,
        CURLOPT_HTTPHEADER,
        headers
    );

    //Anfrage ausführen mit obigen Einstellungen
    CURLcode result = curl_easy_perform(curl);

    int status = 0;

    curl_easy_getinfo(
        curl,
        CURLINFO_RESPONSE_CODE,
        &status
    );

    cout << "Anfrage mit Statuscode: " << status << endl;

    curl_easy_cleanup(curl);
    return 0;
}