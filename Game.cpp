#include "Game.h"

Game::Game()
{
        scene = Scene();
        end = false;
}

Game::~Game()
{
}

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
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
        gotoxy(55, 17);
        printf("%c", tecla);
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
    muerte2();
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
    portada2();
    scene.crearScena();
    while (!end) {
        scene.tiempo();
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

void Game::muerte2() {
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
    printf("Presione ESC para salir o cualquier otra tecla para seguir jugando");
    /*key = _getch();
    if (key == 27)
        exit(1);*/
}


void Game::portada() {
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
    printf("Precione ENTER para empezar");
    system("pause>dsdsd");
    system("cls");
}

void Game::portada2() {
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
    printf("Precione ENTER para empezar");
    system("pause>dsdsd");
    system("cls");
}