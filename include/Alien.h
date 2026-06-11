#ifndef ALIEN_H
#define ALIEN_H

#include "Entity.h"

// OOP: Inheritance — Alien is-a Entity
class Alien : public Entity
{
public:
    static Texture2D second_image; // Shared across all aliens (static)

    Alien(Vector2 pos) : Entity(pos) {}

    // OOP: Polymorphism — overrides pure virtual Draw()
    void Draw() override
    {
        DrawTexture(second_image, position.x, position.y, WHITE);
    }

    // OOP: Polymorphism — overrides pure virtual Update()
    void Update() override {}

    // Overloaded Update with direction parameter
    // OOP: Function overloading
    void Update(int direction)
    {
        position.x += direction;
    }

    static void LoadTextureOnce()
    {
        second_image = LoadTexture("alien_2.png");
    }

    static void UnloadTextureOnce()
    {
        UnloadTexture(second_image);
    }
};

#endif
