#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <conio.h>
#include <array>
#include "Scene.h"

class Game
{
public:

    Game();
    ~Game();

    void tiempo();
    void restricciones();

    void leerTeclado();
    void endGame();
    void run();


private:
    Scene scene;
    bool end;
};


