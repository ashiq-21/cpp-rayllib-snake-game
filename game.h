#include <snake.h>
#include <food.h>

class Game
{
public:
    Game();
    ~Game();
    void draw();
    void update();
    void HandleInput();
    int score;

private:
    Snake snake = Snake();
    Food food = Food(snake.body);
    void checkCollisionFood();
    void checkCollisionEdge();
    void checkCollisionTail();
    void GameOver();
    bool running;
    Sound eatSound;
    Sound wallSound;
    Sound biteSound;
};