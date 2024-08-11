#include <snake.h>

Snake::Snake()
{
    cellSize = 30;
    cellCount = 25;
    offset = 75;
    addSegment = 0;
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}

void Snake::draw()
{
    for (int i = 0; i < (int)body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle rec = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(rec, 0.5, 6, DARKGREEN);
    }
}

void Snake::update()
{
    body.push_front(Vector2Add(body[0], direction));
    if (addSegment)
    {
        addSegment = 0;
    }
    else
    {
        body.pop_back();
    }
}

void Snake::reset()
{
    addSegment = 0;
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}
