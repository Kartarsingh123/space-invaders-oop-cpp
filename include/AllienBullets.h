#ifndef ALLIENBULLETS_H
#define ALLIENBULLETS_H

#include "Entity.h"

// OOP: Inheritance — AllienBullets is-a Entity
class AllienBullets : public Entity
{
public:
    float speed;
    bool  A_b_active;

    AllienBullets(Vector2 pos) : Entity(pos)
    {
        speed      = 4;
        A_b_active = true;
    }

    // OOP: Polymorphism — overrides pure virtual Draw()
    void Draw() override
    {
        DrawRectangle(position.x, position.y, 9, 13, ORANGE);
        DrawRectangle(position.x + 2, position.y + 10, 5, 7, YELLOW);
    }

    // OOP: Polymorphism — overrides pure virtual Update()
    void Update() override
    {
        position.y += speed;
        if (position.y >= GetScreenHeight() - 30)
        {
            A_b_active = false;
        }
    }
};

#endif
