#pragma once
#include <utility>

class Food
{
public:
    Food();
    Food(std::pair<int, int>);
    ~Food();
    void setUbicacion(std::pair<int, int> t_ubicacion);
    std::pair<int, int> getUbicacion();
    char getBody();
private:
    std::pair<int, int> ubicacion;
    int x = 0, y = 0;
    char body;
};



