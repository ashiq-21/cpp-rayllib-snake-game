#include <game.h>

double lastupdatetime = 0;

int offset = 75;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastupdatetime >= interval)
    {
        lastupdatetime = currentTime;
        return 1;
    }
    return 0;
}

int main()
{

    InitWindow(offset * 2 + 750, offset * 2 + 750, "RAYLIB Snake!");

    Game game = Game();

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        game.HandleInput();

        if (EventTriggered(0.2))
        {
            game.update();
        }

        ClearBackground(GREEN);

        Rectangle rec = Rectangle{(float)(offset - 5), (float)(offset - 5), (float)760, (float)760};

        DrawRectangleLinesEx(rec, 5, DARKGREEN);

        DrawText("Raylib Snake", (float)(offset - 5), 20, 40, DARKGREEN);

        DrawText("Score", (float)(offset - 5), 760 + 75, 40, DARKGREEN);

        DrawText(TextFormat("%d", game.score), (float)(offset + 150), 760 + 75, 40, DARKGREEN);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}