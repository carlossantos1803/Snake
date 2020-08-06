#include "Scene.h"

Scene::Scene()
{
    srand(time(NULL));
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    board_X = 100 / 2;
    board_Y = 25;
    food = Food();
    newFood();
    snake = Culebra();
    wall = Wall();
    tipoPared = false;
    std::vector<std::pair<int, int>> pared;
    pared.push_back(std::make_pair(board_X, board_Y));
    wall.setObject(pared);
}

Scene::~Scene()
{
}

void Scene::gotoxy(int t_x, int t_y)
{
    dwPos.X = t_x;
    dwPos.Y = t_y;
    SetConsoleCursorPosition(console, dwPos);
}

void Scene::pintar(Objetos &obj)
{
    SetConsoleTextAttribute(console, obj.getColor());
    for (unsigned int i = 0; i < obj.getObject().size(); ++i) {
        gotoxy(obj.getObject()[i].first, obj.getObject()[i].second);
        printf("%c", obj.getBody()[i]);
    }   
}

void Scene::limpiar(Objetos& obj)
{
    for (const auto& i : obj.getObject()) {
        gotoxy(i.first, i.second);
        printf(" ");
    }
}

void Scene::crearScena() {
    pintar(wall);
    pintar(food);
}

void Scene::update()
{
    if (snake.getObject()[0] == food.getObject()[0]) {
        PlaySound(TEXT("tragar.wav"), NULL, SND_ASYNC);
        snake.growSnake();
        newFood();
        pintar(food);
        
    }
}

void Scene::newFood()
{
    std::vector<std::pair<int, int>> temp;
    unsigned int x = 0, y = 0;
    x = rand() % (board_X - 3) + 3;
    y = rand() % (board_Y - 4) + 3;
    temp.push_back(std::make_pair(x, y));
    for (unsigned int i = 0; i < snake.getObject().size(); ++i) {
        if (snake.getObject()[i] != temp[0]) {
            food.setObject(temp);
            gotoxy(55, 15);
            printf(" %d , %d ", food.getObject()[0].first, food.getObject()[0].second);
         }
        else if (snake.getObject()[i] == temp[0]) {
            newFood();
            break;
        }
    }
    
    
}

void Scene::moveSnake()
{
    limpiar(snake);
    snake.moverSnake();
    pintar(snake);
    gotoxy(55, 16);
    printf(" %d , %d ", snake.getObject()[0].first, snake.getObject()[0].second);
}

void Scene::direccion(char direction)
{   
    if ((snake.getDirection() == 'w' && direction == 's') || 
        (snake.getDirection() == 's' && direction == 'w') ||
        (snake.getDirection() == 'a' && direction == 'd') ||
        (snake.getDirection() == 'd' && direction == 'a')  ) 
    {
        snake.setDirection(snake.getDirection());
    }
    else {
        snake.setDirection(direction);
    }
}

bool Scene::restricciones()
{
   /*for (int i = 1; i < wall.getWall().size(); ++i) {
        if (snake.getSnake()[0] == wall.getWall()[i]) {
            temp = true;
            break;
        }
        
    }*/
    if (snake.restricciones()||tipoPared) {
        return true;
    }
    return false;
}

void Scene::wallMagic(bool type) {
    std::vector<std::pair<int, int>> t_snake = snake.getObject();
    for (unsigned int i = 0; i < wall.getObject().size(); ++i) {
        if (snake.getObject()[0] == wall.getObject()[i]) {
            SetConsoleTextAttribute(console, 15);
            gotoxy(wall.getObject()[i].first, wall.getObject()[i].second);
            printf("%c", wall.getBody()[0]);
            if (!type) {
                tipoPared = true;
                //break;
            }
            else{
                if (snake.getDirection() == 'w') {
                    t_snake[0].second = board_Y - 2;
                }
                else if (snake.getDirection() == 's') {
                    t_snake[0].second = 3;
                }
                else if (snake.getDirection() == 'a') {
                    t_snake[0].first = board_X - 1;
                }
                else if (snake.getDirection() == 'd') {
                    t_snake[0].first = 3;
                }
                tipoPared = false;
            }
            
        }
        
    }
    snake.setObject(t_snake);
}

void Scene::teletransporter() {
   /* SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(board_X / 4, board_Y / 4);
    printf("%c", 219);
    gotoxy((board_X - board_X / 4), (board_Y - board_Y / 4));
    printf("%c", 219);
    if (snake.getSnake()[0] == std::make_pair(board_X/4, board_Y/4) ){
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(board_X / 4, board_Y / 4);
        printf("%c", 219);

        if (snake.getDirection() == 'w') {
            t_snake[0].second = board_Y - 2;
        }
        else if (snake.getDirection() == 's') {
            t_snake[0].second = 3;
        }
        else if (snake.getDirection() == 'a') {
            t_snake[0].first = board_X - 1;
        }
        else if (snake.getDirection() == 'd') {
            t_snake[0].first = 3;
        }
    }*/
}

bool Scene::leerTeclado()
{
    /*if (_kbhit()) {
        char tecla = _getch();
        scene.direccion(tecla);
        if (tecla == 27) {
            end = true;
        }
    }*/
    return false;
}

void Scene::tiempo()
{
    //con este metdo quiero hacer que el juego corra a 30 cuadros por segundo dando una
    static long   t = clock();
    const float fps = 5.0f;

    long toWait = (long)(t + CLOCKS_PER_SEC / fps - clock());
    if (toWait > 0) {
        Sleep(toWait);
    }
    t = clock();
}





