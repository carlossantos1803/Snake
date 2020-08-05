#include "Scene.h"

Scene::Scene()
{
    srand(time(NULL));
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    board_X = 100 / 2;
    board_Y = 25;
    food = Food(std::make_pair(rand() % (board_X - 3) + 3, rand() % (board_Y - 3) + 3));
    snake = Culebra();
    wall = Wall();
    tipoPared = false;
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

void Scene::pintarFood()
{
    SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED);
    gotoxy(food.getUbicacion().first, food.getUbicacion().second);
    printf("%c", 149);
}

void Scene::pintarSnake()
{
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(snake.getSnake()[0].first, snake.getSnake()[0].second);
    printf("%c", 64);
    for (unsigned int i = 1; i < snake.getSnake().size(); ++i) {
        gotoxy(snake.getSnake()[i].first, snake.getSnake()[i].second);
        printf("%c", 79);
    }
}

void Scene::pintar(std::vector<std::pair<int,int>> &obj, char t_body, WORD t_color)
{//con este metodo voy a pintar cada uno de los objetos creados en el juego
    SetConsoleTextAttribute(console,t_color);
    for (unsigned int i = 1; i < obj.size(); ++i) {
        gotoxy(obj[i].first, obj[i].second);
        printf("%c", t_body);
    }
}

void Scene::limpiarSnake()
{
    std::vector<std::pair<int, int>> t_snake = snake.getSnake();
    for (int i = 0; i < t_snake.size(); ++i) {
        gotoxy(t_snake[i].first, t_snake[i].second);
        printf(" ");
    }
}

void Scene::update()
{
    if (snake.getSnake()[0] == food.getUbicacion()) {
        snake.growSnake();
        newFood();
        pintarFood();
    }
}

void Scene::newFood()
{
    std::pair<int, int> temp;
    unsigned int x = 0, y = 0;
    x = rand() % (board_X - 3) + 3;
    y = rand() % (board_Y - 4) + 3;
    temp = std::make_pair(x, y);
    for (int i = 0; i < snake.getSnake().size(); ++i) {
        if (snake.getSnake()[i] != temp) {
            food.setUbicacion(std::make_pair(x, y));
            gotoxy(55, 15);
            printf(" %d , %d ", food.getUbicacion().first, food.getUbicacion().second);
         }
        else if (snake.getSnake()[i] == temp) {
            newFood();
            break;
        }
    }
    
    
}

void Scene::moveSnake()
{
    snake.moverSnake();
    gotoxy(55, 16);
    printf(" %d , %d ", snake.getSnake()[0].first, snake.getSnake()[0].second);
}

void Scene::direccion(char direction)
{   
    if (snake.getDirection() == 'w' && direction == 's' || 
        snake.getDirection() == 's' && direction == 'w' ||
        snake.getDirection() == 'a' && direction == 'd' ||
        snake.getDirection() == 'd' && direction == 'a'  ) 
    {
        snake.setDirection(snake.getDirection());
    }
    else {
        snake.setDirection(direction);
    }
}

bool Scene::restricciones()
{
    bool temp = false;
    /*for (int i = 1; i < wall.getWall().size(); ++i) {
        if (snake.getSnake()[0] == wall.getWall()[i]) {
            temp = true;
            break;
        }
        
    }*/
    if (temp || snake.restricciones()||tipoPared) {
        return true;
    }
    return false;
}

void Scene::makeWall()
{
    wall.setWall(board_X, board_Y);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < wall.getWall().size(); ++i) {
        gotoxy(wall.getWall()[i].first, wall.getWall()[i].second);
        printf("%c", 219);
    }
}


void Scene::wallMagic(bool type) {
    std::vector<std::pair<int, int>> t_snake = snake.getSnake();
    for (int i = 0; i < wall.getWall().size(); ++i) {
        if (snake.getSnake()[0] == wall.getWall()[i]) {
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            gotoxy(wall.getWall()[i].first, wall.getWall()[i].second);
            printf("%c", 219);
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
    snake.setSnake(t_snake);
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

void Scene::muerte2() {
    system("cls");
    int c = 24, f = 79, r;
    char key;
    char t = 178;
    for (int i = 0; i < f; i++) {
        gotoxy(i, 0);
        printf("%c", t);
        gotoxy(i, c);
        printf("%c", t);
    }
    for (int i = 0; i <= c; i++) {
        gotoxy(0, i);
        printf("%c", t);
        gotoxy(f, i);
        printf("%c", t);
    }

    std::string g4meover[] = { "  ____                       ___"," / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ ",
    "| |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__|","| |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ | ",
    " \\____|\\__,_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|" };
    r = 2;
    for (int i = 0; i < 5; i++) {
        gotoxy(15, r);
        r++;
        std::cout << g4meover[i] << std::endl;
        
    }

    std::string g4meover2[] = { "   _________         _________","  /         \\       /         \\",
    " /  /~~~~~\\  \\     /  /~~~~~\\  \\"," |  |     |  |     |  |     |  |"," |  |     |  |     |  |     |  |",
    " |  |     |  |     |  |     |  |         /"," |  |     |  |     |  |     |  |       //","(X  X)    \\  \\_____/  /     \\  \\_____/ /",
    " \\__/      \\         /       \\        /","  |         ~~~~~~~~~         ~~~~~~~~","  ^" };
    for (int i = 0; i < 11; i++) {
        gotoxy(20, r);
        std::cout << g4meover2[i] << std::endl;
        r++;

    }
    gotoxy(8, 23);
    printf( "Presione ESC para salir o cualquier otra tecla para seguir jugando");
    /*key = _getch();
    if (key == 27)
        exit(1);*/
}


void Scene::portada() {
    system("cls");
    int c = 24, f = 79, r;
    char t = 178;
    for (int i = 0; i < f; i++) {
        gotoxy(i, 0);
        printf("%c", t);
        gotoxy(i, c);
        printf("%c", t);
    }
    for (int i = 0; i <= c; i++) {
        gotoxy(0, i);
        printf("%c", t);
        gotoxy(f, i);
        printf("%c", t);
    }
    std::string snkd[] = { "       ---_ ......._-_--.","      (|\\ /      / /| \\  \\","      /  /     .'  -=-'   `.",
            "     /  /    .'             )","   _/  /   .'        _.)   /","  / o   o        _.-' /  .'",
            "  \\          _.-'    / .'*|","   \\______.-'//    .'.' \\*|","    \\|  \\ | //   .'.' _ |*|",
            "     `   \\|//  .'.'_ _ _|*|","      .  .// .'.' | _ _ \\*|","      \\`-|\\_/ /    \\ _ _ \\*\\",
            "                     \\ _ _ \\*","                      \\ _ _ \\ ","                       \\_" };

    r = 2;
    for (int i = 0; i < 14; i++) {
        gotoxy(20, r);
        r++;
        std::cout << snkd[i] << std::endl;
    }

    std::string snkl[] = { "                     __     ","   _________  ____ _/ /_____","  / ___/ __ \\/ __ `/ //_/ _ \\",
    " (__  ) / / / /_/ / ,< /  __/","/____/_/ /_/\\__,_/_/|_|\\___/" };
    for (int i = 0; i < 5; i++) {
        gotoxy(22, r);
        r++;
        std::cout << snkl[i] << std::endl;
    }
    gotoxy(23, 23);
    printf( "Precione ENTER para empezar");
    system("pause>dsdsd");
    system("cls");
}

void Scene::portada2() {
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 13);
    system("color 0a");
    system("cls");
    int c = 24, f = 79, r;
    char t = 178;
    for (int i = 0; i < f; i++) {
        gotoxy(i, 0);
        printf("%c", t);
        gotoxy(i, c);
        printf("%c", t);
    }
    for (int i = 0; i <= c; i++) {
        gotoxy(0, i);
        printf("%c", t);
        gotoxy(f, i);
        printf("%c", t);
    }
    std::string snkd[] = { "       ---_ ......._-_--.","      (|\\ /      / /| \\  \\","      /  /     .'  -=-'   `.",
            "     /  /    .'             )","   _/  /   .'        _.)   /","  / o   o        _.-' /  .'",
            "  \\          _.-'    / .'*|","   \\______.-'//    .'.' \\*|","    \\|  \\ | //   .'.' _ |*|",
            "     `   \\|//  .'.'_ _ _|*|","      .  .// .'.' | _ _ \\*|","      \\`-|\\_/ /    \\ _ _ \\*\\",
            "                     \\ _ _ \\*","                      \\ _ _ \\ ","                       \\_" };

    r = 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 13);
    for (int i = 0; i < 14; i++) {
        gotoxy(20, r);
        r++;
        std::cout << snkd[i] << std::endl;
    }

    std::string snkl[] = { "                     __     ","   _________  ____ _/ /_____","  / ___/ __ \\/ __ `/ //_/ _ \\",
    " (__  ) / / / /_/ / ,< /  __/","/____/_/ /_/\\__,_/_/|_|\\___/" };
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 14);
    for (int i = 0; i < 5; i++) {
        gotoxy(22, r);
        r++;
        std::cout << snkl[i] << std::endl;
    }
    gotoxy(23, 23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
    printf( "Precione ENTER para empezar");
    system("pause>dsdsd");
    system("cls");
}





