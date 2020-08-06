#pragma once
#include <vector>
#include <utility>
typedef unsigned short int WORD;

class Objetos
{
public:
    virtual ~Objetos() {};
    virtual void setObject(const std::vector<std::pair<int, int>>& t_object) = 0;
    virtual std::vector < std::pair<int, int >> getObject() = 0;
    virtual std::vector<char> getBody() = 0;
    virtual WORD getColor() = 0;
};



