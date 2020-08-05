#pragma once

#include <vector>
#include <utility>
class Wall
{
public:
    Wall();
    ~Wall();
    void setTipoPared(bool t_tipo);
    void setWall(int board_X, int board_Y);
    std::vector < std::pair<int, int>> getWall();
private:
    bool paredNormal;
    std::vector < std::pair<int, int>> pared;
    char body;
};


