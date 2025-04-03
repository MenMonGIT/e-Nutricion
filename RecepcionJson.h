#ifndef RECEPCIONJSON_H
#define RECEPCIONJSON_H
#include "PeticionCurl.h"
#include <string>

class RecepcionJson{
    public:
        RecepcionJson();
        std::string Json(std::string response);

};


#endif //RECEPCIONJSON_H