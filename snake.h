#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <deque>
using namespace std;

class Snake
{
public:
    Snake();
    deque<Vector2> body;
    Vector2 direction;
    int cellSize;
    int cellCount;
    int offset;
    bool addSegment;
    void draw();
    void update();
    void reset();
};