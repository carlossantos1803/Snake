#include "Food.h"

    Food::Food(){
        body.push_back(149);
        color = 12;
    }
    Food::~Food() {};
    
    void Food::setObject(const std::vector<std::pair<int, int>>& t_object)
    {
        ubicacion = t_object;
    }
    
    std::vector<std::pair<int, int>> Food::getObject()
    {
        return ubicacion;
    }

    std::vector<char> Food::getBody()
    {
        return body;
    }

    WORD Food::getColor()
    {
        return color;
    }

