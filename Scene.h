#pragma once
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Food.h"
#include "Culebra.h"
#include "Wall.h"
#include <string>
#include <iostream>

class Scene
{
public:
	Scene();
	~Scene();
	void gotoxy(int t_x, int t_y);
	void pintar(Objetos &obj);
	void limpiar(Objetos& obj);
	void crearScena();
	void update();
	void newFood();
	void moveSnake();
	void direccion(char);
	bool restricciones();
	void wallMagic(bool);
	void teletransporter();
	bool leerTeclado();
	void tiempo();
private:
	COORD dwPos;
	HANDLE console;
	Food food;
	Culebra snake;
	Wall wall;
	int board_X = 0;
	int board_Y = 0;
	bool tipoPared;
};



