#include <iostream>
#include <raylib.h>
#include <vector>
#include <algorithm>
#include "Game.h"
using namespace std;

// Global variables — declared here, extern in headers
float score          = 0;
float spaceship_scale = 0.185f;
float LastTime       = 0.0;
int   down_value     = 3;
int   lives          = 3;
float shootDelay     = 0.9f;
float shootTimer     = 0.0f;

// Static member defined once here
Texture2D Alien::second_image;

// For Game Over
bool IsGameOver()
{
    if (lives <= 0)
    {
        return false;
    }
    return true;
}

bool IsGameWon(Game &game)
{
    if (game.AliensAllDead())
    {
        return true;
    }
    return false;
}

// Colors
Color gray   = {29, 29, 27, 255};
Color yellow = {243, 216, 63, 255};

int main()
{
    int screen_width  = 800;
    int screen_height = 750;
    InitWindow(screen_width, screen_height, "Space Invaders");
    SetTargetFPS(50);

    Game game;
    Alien::LoadTextureOnce();

    while (WindowShouldClose() == false)
    {
        game.InputHandling();

        if (IsGameOver() == false || IsGameWon(game) == true)
        {
            if (IsKeyPressed(KEY_R))
            {
                game.ResetGame();
            }
        }

        if (IsGameOver() == true && IsGameWon(game) == false)
        {
            game.Update();
        }

        BeginDrawing();
        ClearBackground(gray);

        if (IsGameOver() == true && IsGameWon(game) == false)
        {
            game.Draw();
        }
        else if (IsGameWon(game) == true)
        {
            DrawText("YOU WIN!", 190, 280, 95, GREEN);
            DrawText("PRESS R TO RESTART", 210, 400, 30, WHITE);
        }
        else
        {
            DrawText("GAME OVER", 100, 280, 95, RED);
            DrawText("PRESS R TO RESTART", 210, 400, 30, WHITE);
        }

        EndDrawing();
    }

    Alien::UnloadTextureOnce();
    CloseWindow();
    return 0;
}
