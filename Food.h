#pragma once
#include "Objetos.h"

class Food : 
    public Objetos
{
public:
    Food();
    ~Food();
    void setObject(std::vector<std::pair<int, int>> t_object) override;
    std::vector<std::pair<int, int>> getObject() override;
    std::vector<char> getBody() override;
    WORD getColor() override;
private:
    std::vector<std::pair<int, int>> ubicacion;
    std::vector<char> body;
    WORD color;
};



