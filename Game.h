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

    void restricciones();
    void muerte2();
    void portada();
    void portada2();
    void leerTeclado();
    void endGame();
    void run();


private:
    Scene scene;
    bool end;
};


