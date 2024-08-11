#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <deque>
using namespace std;

class Food
{
public:
    Food(deque<Vector2> body);
    ~Food();
    void draw();
    bool checkPoint(Vector2 pos, deque<Vector2> body);
    Vector2 randomPoint();
    Vector2 generateRandomPoint(deque<Vector2> body);
    Vector2 position;
    int cellSize;
    int cellCount;
    int offset;
    Texture2D txt;
};