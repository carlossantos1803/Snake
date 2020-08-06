#pragma once

#include "Objetos.h"
class Wall :
    public Objetos
{
public:
    Wall();
    ~Wall();
    void setTipoPared(bool t_tipo);
    void setObject(std::vector<std::pair<int,int>> t_object) override;
    std::vector < std::pair<int, int>> getObject() override;
    std::vector<char> getBody() override;
    WORD getColor() override;
private:
    bool paredNormal;
    std::vector < std::pair<int, int>> pared;
    std::vector<char> body;
    WORD color;
};


