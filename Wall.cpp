#include "Wall.h"

Wall::Wall() : paredNormal(true) {
    body.push_back(219);
    color = 15;
};

Wall::~Wall()
{
}

void Wall::setTipoPared(bool t_tipo)
{
	paredNormal = t_tipo;
}

void Wall::setObject(std::vector<std::pair<int, int>> t_object)
{
    for (int i = 3; i < t_object[0].first; ++i) {
        pared.push_back(std::make_pair(i, 2));
        pared.push_back(std::make_pair(i, t_object[0].second - 1));
    }
    for (int i = 2; i < t_object[0].second; ++i) {
        pared.push_back(std::make_pair(2, i));
        pared.push_back(std::make_pair(t_object[0].first, i));
    }
}


std::vector<std::pair<int, int>> Wall::getObject()
{
    return pared;
}

std::vector<char> Wall::getBody()
{
    return body;
}

WORD Wall::getColor()
{
    return color;
}
