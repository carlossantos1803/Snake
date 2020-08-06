#pragma once
#include "Objetos.h"
class Culebra : 
    public Objetos
{
public:
    Culebra();
    ~Culebra();
    std::vector<std::pair<int, int>> getObject() override;
    void setObject(std::vector <std::pair<int, int>> t_snake) override;
    char getDirection();
    void setDirection(char t_direction);
    bool restricciones();
    void growSnake();
    void moverSnake();
    std::vector<char> getBody();
    WORD getColor() override;

private:
    std::vector <std::pair<int, int>> snake;
    char direction;
    std::vector<char> body;
    WORD color;
};





