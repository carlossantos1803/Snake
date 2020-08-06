#include "Game.h"

Game::Game()
{
        scene = Scene();
        end = false;
}

Game::~Game()
{
}

void Game::tiempo()
{
    //con este metdo quiero hacer que el juego corra a 30 cuadros por segundo dando una
    static long   t = clock();
    const float fps = 5.0f;

    long toWait = t + CLOCKS_PER_SEC / fps - clock();
    if (toWait > 0) {
        Sleep(toWait);
    }
    t = clock();
}

void Game::restricciones()
{
    //aqui van los if los cuales limitaran el movimiento de la snake
    if (scene.restricciones()) {
        end = true;
    }
}

void Game::leerTeclado()
{
    //char tecla = ' ';
    if (_kbhit()) {
        char tecla = _getch();
        scene.direccion(tecla);
        if (tecla == 27) {
            end = true;
            //endGame();
        }
    }
    //return tecla;
}

void Game::endGame()
{
    //if (end) {
    scene.muerte2();
    //}
    while (!_kbhit()) {}
    if (_kbhit()) {
        char tecla = _getch();
        if (tecla == 27) {
            exit(1);
        }
        else {
            end = false;
            scene = Scene();
            run();
        }
    }
}

void Game::run()
{
    scene.portada2();
    scene.makeWall();
    scene.pintarFood();
    //scene.pintar()
    while (!end) {
        tiempo();
        scene.limpiarSnake();
        scene.moveSnake();
        scene.wallMagic(true);
        //scene.teletransporter();
        scene.update();

        restricciones();
        leerTeclado();
        //scene.direccion(leerTeclado());
    }
    endGame();
}
