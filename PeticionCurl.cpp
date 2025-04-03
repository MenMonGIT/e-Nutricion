#include "PeticionCurl.h"
#include <curl/curl.h>
#include <iomanip>
#include <sstream>

using namespace std;

PeticionCurl::PeticionCurl(){

}

std::string urlEncode(const std::string& value) {
    std::ostringstream encoded;
    encoded << std::hex << std::uppercase;

    for (unsigned char c : value) {
        // Si es alfanumérico, guión, subrayado o punto, lo dejamos sin cambios
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            // Si no, lo convertimos a %XX
            encoded << '%' << std::setw(2) << int(c);
        }
    }

    return encoded.str();
}

// Función de callback para manejar la respuesta
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}


std::string PeticionCurl::peticionC(std::string receta){
    //Ejemplo de receta: 1 cup rice, 10 oz chickpeas
    string response;
    CURL* curl;
    CURLcode res;
        
    // Tu Application ID y Key
    std::string app_id = "66c863b9";
    std::string app_key = "3b797da8030d8bbace629fccab47de17";
        
    // URL de la API con parámetros
    std::string url = "https://api.edamam.com/api/nutrition-data?app_id=" + app_id + "&app_key=" + app_key + "&ingr="+urlEncode(receta);
    
    // Inicializa curl
    curl = curl_easy_init();
    if(curl) {
            // Configura la URL
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    
            // Callback para almacenar la respuesta en una cadena
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
            // Realiza la solicitud
            res = curl_easy_perform(curl);
    
            // Verifica el resultado
            if(res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            } else {
                // Muestra la respuesta JSON de la API
              //  std::cout << "Respuesta de la API: " << response << std::endl;
            }
    
            // Limpia la memoria
            curl_easy_cleanup(curl);
    }
    return response;    
}



