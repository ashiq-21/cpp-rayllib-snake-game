#include <snake.h>
#include <food.h>

class Game
{
public:
    Game();
    ~Game();
    Snake snake = Snake();
    Food food = Food(snake.body);
    void draw();
    void update();
    void HandleInput();
    void checkCollisionFood();
    void checkCollisionEdge();
    void checkCollisionTail();
    void GameOver();
    bool running;
    int score;
    Sound eatSound;
    Sound wallSound;
};