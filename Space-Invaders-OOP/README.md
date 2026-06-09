# Space Invaders — C++ & Raylib

A Space Invaders arcade game built from scratch in C++ using the Raylib graphics library. I designed the whole thing around OOP — every game element is its own class, and they all connect through a shared base class.

It started as a single-file project, then I refactored it into a proper class hierarchy with header files. That refactor taught me more about OOP than anything else.

---

## Features

- Player spaceship with left/right movement and shooting
- Alien grid that moves side to side and descends toward you
- Aliens fire back — so you actually have to dodge
- Collision detection for both player and alien bullets
- Score system — 10 points per alien killed
- 3 lives before game over
- Win screen when all aliens are cleared
- Game over screen with restart option (`R` to restart)
- Smooth 60 FPS gameplay loop

---

## OOP Design

| Concept | How I applied it |
|:--------|:----------------|
| **Abstraction** | `Entity` is an abstract base class with pure virtual functions |
| **Inheritance** | `Spaceship`, `Alien`, `Laser`, and `AlienBullets` all inherit from `Entity` |
| **Polymorphism** | `Draw()` and `Update()` are virtual in `Entity`, overridden in every subclass |
| **Encapsulation** | `position` and `speed` are `protected` in the base class, accessed through getters |
| **Modular Design** | Each class lives in its own `.h` header file |

### Class Hierarchy

```
Entity  (abstract base class)
│
├── Spaceship       → player, moves left/right, fires lasers
├── Alien           → enemy, moves in formation, fires bullets
├── Laser           → player bullet, travels upward
└── AlienBullets    → alien bullet, travels downward
```

---

## Project Structure

```
Space-Invaders-OOP/
│
├── src/
│   ├── Space_Invaders2.cpp     # Main file — OOP version
│   ├── Space_invaders.cpp      # Original single-file version
│   ├── Entity.h                # Abstract base class
│   ├── Spaceship.h             # Player class
│   ├── Alien.h                 # Alien enemy class
│   ├── Laser.h                 # Player bullet class
│   ├── AlienBullets.h          # Alien bullet class
│   ├── Game.h                  # Main game controller
│   ├── Rocket.png              # Player sprite
│   └── alien_2.png             # Alien sprite
│
└── README.md
```

---

## Controls

| Key | Action |
|:----|:-------|
| `A` or `←` | Move left |
| `D` or `→` | Move right |
| `Spacebar` | Shoot |
| `R` | Restart |
| `Esc` | Quit |

---

## How to Run

**Requirements**
- G++ compiler with C++17 support
- [Raylib 5.5](https://www.raylib.com/) installed
- Windows

**Compile and run**

```bash
g++ -std=c++17 Space_Invaders2.cpp -o Space_Invaders2 -I. -lraylib -lopengl32 -lgdi32 -lwinmm
./Space_Invaders2
```

**Using VS Code**
1. Open the project folder in VS Code
2. Press `Ctrl + Shift + B` → select **Build Space Invaders 2**
3. Press `F5` → select **Debug Space Invaders 2**

---

## Developer

**Kartar Singh**  
CS Student @ IBA Karachi  
[github.com/Kartarsingh123](https://github.com/Kartarsingh123)
