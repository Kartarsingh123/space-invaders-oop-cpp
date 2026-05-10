#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

// Abstract Base Class — provides interface for all game entities
// OOP: Abstraction, Encapsulation, Polymorphism
class Entity
{
protected:
    Vector2 position; // Encapsulated — accessible to derived classes only

public:
    Entity(Vector2 pos) : position(pos) {}

    virtual ~Entity() = default; // Virtual destructor — required for polymorphism

    // Pure virtual functions — makes Entity abstract (cannot be instantiated)
    // OOP: Polymorphism via virtual dispatch
    virtual void Draw()   = 0;
    virtual void Update() = 0;

    Vector2 GetPosition() const { return position; }

    // OOP: Operator overloading — compare entities by Y position
    bool operator<(const Entity& other) const
    {
        return position.y < other.position.y;
    }
};

#endif
