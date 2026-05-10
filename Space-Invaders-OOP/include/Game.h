#ifndef GAME_H
#define GAME_H

#include "Spaceship.h"
#include "Alien.h"
#include "AllienBullets.h"
#include <vector>
#include <algorithm>
using namespace std;

extern float shootDelay;
extern float shootTimer;
extern int   down_value;

class Game
{
private:
    Spaceship spaceship;
    vector<Alien> alien;
    vector<AllienBullets> allien_bullets;
    int alienDirection = 1;

public:
    Game()
    {
        CreateAlien();
    }

    bool AliensAllDead()
    {
        return alien.empty();
    }

    void Draw()
    {
        spaceship.Draw();
        for (int i = 0; i < alien.size(); i++)
        {
            alien[i].Draw();
        }
        for (int i = 0; i < spaceship.laser.size(); i++)
        {
            spaceship.laser[i].Draw();
        }
        for (int i = 0; i < allien_bullets.size(); i++)
        {
            allien_bullets[i].Draw();
        }
        DrawText(TextFormat("Score: %i", (int)score), GetScreenWidth() - 200, 15, 30, WHITE);
        DrawText(TextFormat("LIVES: %i", (int)lives), 90, 17, 30, WHITE);
        DrawLineEx({0, (float)GetScreenHeight() - 20}, {(float)GetScreenWidth(), (float)GetScreenHeight() - 20}, 5, WHITE);
    }

    void Update()
    {
        MoveAlien();
        AlienShoot();
        AlienMissileDetection();
        for (int i = 0; i < spaceship.laser.size(); i++)
        {
            spaceship.laser[i].Update();
        }
        DetectCollision();
        spaceship.laser.erase(
            remove_if(spaceship.laser.begin(), spaceship.laser.end(),
                      [](Laser &l1) { return l1.active == false; }),
            spaceship.laser.end());
        for (int i = 0; i < allien_bullets.size(); i++)
        {
            allien_bullets[i].Update();
        }
        allien_bullets.erase(
            remove_if(allien_bullets.begin(), allien_bullets.end(),
                      [](AllienBullets &A1) { return A1.A_b_active == false; }),
            allien_bullets.end());
    }

    void InputHandling()
    {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        {
            spaceship.MoveLeft();
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        {
            spaceship.MoveRight();
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            spaceship.FireShooter();
        }
    }

    void CreateAlien()
    {
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 11; col++)
            {
                float x = (col * 65) + 90;
                float y = (row * 65) + 100;
                alien.push_back(Alien({x, y}));
            }
        }
    }

    void MoveAlien()
    {
        if (alien.empty())
        {
            return;
        }
        float rightmost = alien[0].GetPosition().x + Alien::second_image.width;
        float leftmost  = alien[0].GetPosition().x;
        bool  movedown  = false;
        for (int i = 0; i < alien.size(); i++)
        {
            if ((alien[i].GetPosition().x + Alien::second_image.width) > rightmost)
            {
                rightmost = alien[i].GetPosition().x + Alien::second_image.width;
            }
            if (alien[i].GetPosition().x < leftmost)
            {
                leftmost = alien[i].GetPosition().x;
            }
        }
        if (rightmost >= GetScreenWidth())
        {
            alienDirection = -1;
            movedown = true;
        }
        if (leftmost <= 0)
        {
            alienDirection = 1;
            movedown = true;
        }
        if (movedown)
        {
            for (int i = 0; i < alien.size(); i++)
            {
                alien[i].position.y += down_value;
            }
            movedown = false;
        }
        for (int i = 0; i < alien.size(); i++)
        {
            alien[i].Update(alienDirection);
        }
    }

    void DetectCollision()
    {
        for (int i = 0; i < spaceship.laser.size(); i++)
        {
            Rectangle LaserRectangle = {spaceship.laser[i].GetPosition().x, spaceship.laser[i].GetPosition().y, 4, 15};
            for (int j = 0; j < alien.size(); j++)
            {
                Rectangle AlienRectangle = {alien[j].GetPosition().x, alien[j].GetPosition().y,
                                            Alien::second_image.width, Alien::second_image.height};
                if (CheckCollisionRecs(LaserRectangle, AlienRectangle))
                {
                    score += 10;
                    spaceship.laser[i].active = false;
                    alien.erase(alien.begin() + j);
                    break;
                }
            }
        }
    }

    void AlienShoot()
    {
        shootTimer += GetFrameTime();
        if (shootTimer > shootDelay)
        {
            shootTimer = 0;
            if (alien.empty()) return;
            int index = rand() % alien.size();
            allien_bullets.push_back(
                AllienBullets({alien[index].GetPosition().x + Alien::second_image.width / 2 - 2,
                               alien[index].GetPosition().y + Alien::second_image.height}));
        }
    }

    void AlienMissileDetection()
    {
        Rectangle Space_Rec = {spaceship.GetPosition().x, spaceship.GetPosition().y,
                               spaceship.GetImage().width  * spaceship_scale,
                               spaceship.GetImage().height * spaceship_scale};
        for (int i = 0; i < allien_bullets.size(); i++)
        {
            Rectangle bullet_Rec = {allien_bullets[i].GetPosition().x, allien_bullets[i].GetPosition().y, 4, 15};
            static float coolDown = 0;
            coolDown -= GetFrameTime();
            if (CheckCollisionRecs(bullet_Rec, Space_Rec) && coolDown <= 0)
            {
                allien_bullets[i].A_b_active = false;
                lives--;
                coolDown = 0.5f;
            }
        }
    }

    void ResetGame()
    {
        lives = 3;
        score = 0;
        alienDirection = 1;
        spaceship.laser.clear();
        allien_bullets.clear();
        alien.clear();
        CreateAlien();
        spaceship.position.x = (GetScreenWidth()  / 2) - 40;
        spaceship.position.y =  GetScreenHeight() - 140;
    }
};

#endif
