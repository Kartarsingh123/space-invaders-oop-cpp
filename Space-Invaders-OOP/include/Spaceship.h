#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"
#include "Laser.h"
#include <vector>
#include <iostream>
using namespace std;

extern float spaceship_scale;
extern float LastTime;
extern float score;
extern int   lives;

// OOP: Inheritance — Spaceship is-a Entity
class Spaceship : public Entity
{
private:
    Texture2D image; // OOP: Encapsulation — private member

public:
    vector<Laser> laser;

    Spaceship() : Entity({0, 0})
    {
        image      = LoadTexture("Rocket.png");
        position.x = (GetScreenWidth()  / 2) - 40;
        position.y =  GetScreenHeight() - 140;
    }

    ~Spaceship()
    {
        UnloadTexture(image);
    }

    // OOP: Polymorphism — overrides pure virtual Draw()
    void Draw() override
    {
        DrawTextureEx(image, position, 0.0, spaceship_scale, WHITE);
    }

    // OOP: Polymorphism — overrides pure virtual Update()
    void Update() override {}

    void MoveLeft()
    {
        position.x -= 5;
        if (position.x < 0)
        {
            position.x = 0;
        }
    }

    void MoveRight()
    {
        position.x += 5;
        if (position.x > GetScreenWidth() - image.width * spaceship_scale)
        {
            position.x = GetScreenWidth() - image.width * spaceship_scale;
        }
    }

    void FireShooter()
    {
        if (GetTime() - LastTime >= 0.36)
        {
            laser.push_back(Laser({position.x + 37, position.y - 10}));
            LastTime = GetTime();
        }
    }

    Texture2D GetImage() const { return image; }

    // OOP: Operator overloading — print spaceship status
    friend ostream& operator<<(ostream& os, const Spaceship& s)
    {
        os << "Spaceship [Score: " << (int)score << " | Lives: " << lives << "]";
        return os;
    }
};

#endif
