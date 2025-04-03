#ifndef PETICIONCURL_H
#define PETICIONCURL_H
#include <string>
#include <iostream>
  
class PeticionCurl {
private:
    std::string receta;
    std::string response;
public:

    PeticionCurl(); //constructor

    std::string peticionC(std::string receta);  //realizar la peticion

    //zona de setters
    void setReceta(std::string receta) {this->receta=receta;}
    void setResponse(std::string response) {this->response=response;}

    //zona de getters
   std::string getReceta() const {return receta;}
   std::string getResponse() const {return response;}

};

#endif // PETICIONCURL_H