#include <game.h>

Game::Game()
{
    running = 1;
    score = 0;
    InitAudioDevice();
    eatSound = LoadSound("Sounds/eat.mp3");
    wallSound = LoadSound("Sounds/wall.mp3");
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::draw()
{
    food.draw();
    snake.draw();
}

void Game::update()
{
    if (running)
    {
        snake.update();
        checkCollisionFood();
        checkCollisionEdge();
        checkCollisionTail();
    }
}

void Game::HandleInput()
{
    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1)
    {
        snake.direction = {0, -1};
        running = 1;
    }
    if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
    {
        snake.direction = {0, 1};
        running = 1;
    }
    if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
    {
        snake.direction = {-1, 0};
        running = 1;
    }
    if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
    {
        snake.direction = {1, 0};
        running = 1;
    }
}

void Game::checkCollisionFood()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.generateRandomPoint(snake.body);
        snake.addSegment = 1;
        score++;
        PlaySound(eatSound);
    }
}

void Game::checkCollisionEdge()
{
    if (snake.body[0].x == snake.cellCount || snake.body[0].x == -1)
    {
        GameOver();
        PlaySound(wallSound);
    }
    if (snake.body[0].y == snake.cellCount || snake.body[0].y == -1)
    {
        GameOver();
        PlaySound(wallSound);
    }
}

void Game::checkCollisionTail()
{
    deque<Vector2> headLess = snake.body;
    headLess.pop_front();
    if (!food.checkPoint(snake.body[0], headLess))
    {
        GameOver();
    }
}

void Game::GameOver()
{
    snake.reset();
    food.position = food.generateRandomPoint(snake.body);
    running = 0;
    score = 0;
}
