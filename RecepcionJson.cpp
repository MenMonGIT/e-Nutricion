#include "RecepcionJson.h"
#include "nlohmann/json.hpp"

RecepcionJson::RecepcionJson(){

}

std::string RecepcionJson::Json(std::string response){

    nlohmann::json jsonResponse = nlohmann::json::parse(response);
    // Acceder a los datos del JSON
    std::string calorias = std::to_string(jsonResponse["calories"].get<double>());
    return calorias;   
}

