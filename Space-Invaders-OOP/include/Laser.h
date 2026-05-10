#ifndef LASER_H
#define LASER_H

#include "Entity.h"

// OOP: Inheritance — Laser is-a Entity
class Laser : public Entity
{
private:
    int speed; // OOP: Encapsulation — private member

public:
    bool active;

    Laser(Vector2 pos) : Entity(pos)
    {
        speed  = 5;
        active = true;
    }

    // OOP: Polymorphism — overrides pure virtual Draw()
    void Draw() override
    {
        DrawRectangle(position.x, position.y, 3, 15, SKYBLUE);
        DrawRectangle(position.x, position.y, 1, 15, WHITE);
    }

    // OOP: Polymorphism — overrides pure virtual Update()
    void Update() override
    {
        position.y -= speed;
        if (position.y < 0)
        {
            active = false;
        }
    }

    Vector2 GetPosition()
    {
        return position;
    }
};

#endif
