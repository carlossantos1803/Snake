#include "Food.h"

    Food::Food(){}
    Food::Food(std::pair<int, int> t_ubicacion) : ubicacion(t_ubicacion), body(149) {};
    Food::~Food() {};
    void Food::setUbicacion(std::pair<int, int> t_ubicacion) {
        ubicacion = t_ubicacion;
    }
    std::pair<int, int> Food::getUbicacion() {
        return ubicacion;
    }

    char Food::getBody()
    {
        return body;
    }

