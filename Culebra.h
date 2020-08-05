#pragma once
#include <utility>
#include <vector>
class Culebra
{
public:
    Culebra();
    ~Culebra();
    std::vector<std::pair<int, int>> getSnake();
    void setSnake(std::vector <std::pair<int, int>> t_snake);
    char getDirection();
    void setDirection(char t_direction);
    bool restricciones();
    void growSnake();
    void moverSnake();

private:
    std::vector <std::pair<int, int>> snake;
    char direction;
};





