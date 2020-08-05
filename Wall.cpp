#include "Wall.h"

Wall::Wall() : paredNormal(true) {};

Wall::~Wall()
{
}

void Wall::setTipoPared(bool t_tipo)
{
	paredNormal = t_tipo;
}

void Wall::setWall(int board_X, int board_Y)
{
    for (int i = 3; i < board_X; ++i) {
        pared.push_back(std::make_pair(i, 2));
        pared.push_back(std::make_pair(i, board_Y - 1));
    }
    for (int i = 2; i < board_Y; ++i) {
        pared.push_back(std::make_pair(2, i));
        pared.push_back(std::make_pair(board_X, i));
    }
}

std::vector<std::pair<int, int>> Wall::getWall()
{
    return pared;
}
