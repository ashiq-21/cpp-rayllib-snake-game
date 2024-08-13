#include <food.h>

Food::Food(deque<Vector2> body)
{
    cellSize = 30;
    cellCount = 25;
    offset = 75;
    txt = LoadTexture("img/food.png");
    position = generateRandomPoint(body);
}

Food::~Food()
{
    UnloadTexture(txt);
}

void Food::draw()
{
    DrawTexture(txt, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

bool Food::checkPoint(Vector2 pos, deque<Vector2> body)
{
    for (int i = 0; i < (int)body.size(); i++)
    {
        if (Vector2Equals(body[i], pos))
        {
            return false;
        }
    }
    return true;
}

Vector2 Food::randomPoint()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

Vector2 Food::generateRandomPoint(deque<Vector2> body)
{
    Vector2 pos = randomPoint();
    while (!checkPoint(pos, body))
    {
        pos = randomPoint();
    }
    return pos;
}
