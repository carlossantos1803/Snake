#include "Culebra.h"

    Culebra::Culebra() {
        direction = 's';
        for (int i = 0; i < 3; ++i) {
            snake.push_back(std::make_pair(8, 10 - i));
        }
    };
    Culebra::~Culebra() {};

    std::vector<std::pair<int, int>> Culebra::getSnake() {
        return snake;
    }
    void Culebra::setSnake(std::vector <std::pair<int, int>> t_snake) {
        snake = t_snake;
    }
    char Culebra::getDirection() {
        return direction;
    }
    void Culebra::setDirection(char t_direction) {
            direction = t_direction;
     }
    bool Culebra::restricciones() {
        //aqui van los if los cuales limitaran el movimiento de la snake
        for (int i = 1; i < snake.size(); ++i) {
            if (snake[0] == snake[i]) {
                return true;
            }
        }
        return false;
    }
    void Culebra::growSnake() {
        unsigned int x = snake[snake.size() - 1].first -
            snake[snake.size() - 2].first;
        unsigned int y = snake[snake.size() - 1].second -
            snake[snake.size() - 2].second;

        x = snake[snake.size() - 1].first + x;
        y = snake[snake.size() - 1].second + y;
        snake.push_back(std::make_pair(x, y));
    }

    void Culebra::moverSnake()
    {
        if (direction == 's') {
            for (int i = snake.size() - 1; i > 0; --i) {
                snake[i].first = snake[i - 1].first;
                snake[i].second = snake[i - 1].second;
            }
            snake[0].second = snake[0].second + 1;
        }
        else if (direction == 'w') {
            for (int i = snake.size() - 1; i > 0; --i) {
                snake[i].first = snake[i - 1].first;
                snake[i].second = snake[i - 1].second;
            }
            snake[0].second = snake[0].second - 1;
        }
        else if (direction == 'd') {
            for (int i = snake.size() - 1; i > 0; --i) {
                snake[i].first = snake[i - 1].first;
                snake[i].second = snake[i - 1].second;
            }
            snake[0].first = snake[0].first + 1;
        }
        else if (direction == 'a') {
            for (int i = snake.size() - 1; i > 0; --i) {
                snake[i].first = snake[i - 1].first;
                snake[i].second = snake[i - 1].second;
            }
            snake[0].first = snake[0].first - 1;
        }
    }



     
