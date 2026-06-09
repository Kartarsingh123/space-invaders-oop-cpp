# 🎮 Space Invaders — OOP C++ Game

![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue?style=flat-square)
![Raylib](https://img.shields.io/badge/Library-Raylib-red?style=flat-square)
![OOP](https://img.shields.io/badge/Concepts-OOP-green?style=flat-square)
![IBA](https://img.shields.io/badge/Institute-IBA%20Karachi-yellow?style=flat-square)

A Space Invaders arcade game built from scratch in **C++** using the **Raylib** graphics library. Every game element is its own class — all connected through a shared abstract base class.

It started as a single-file project, then I refactored it into a proper class hierarchy with header files. That refactor taught me more about OOP design than anything else.

---

## 🚀 Features

- 🚀 Player-controlled spaceship with smooth movement
- 👾 Alien grid that moves side to side and descends toward you
- 🔫 Player shooting mechanics
- 💥 Aliens fire back — you have to dodge too
- 🎯 Collision detection for both player and alien bullets
- 🏆 Score system (+10 per alien killed)
- ❤️ 3 lives before game over
- 🎉 Win screen when all aliens are cleared
- 💀 Game over screen with restart option
- 🔄 Restart anytime with `R`
- ⚡ Smooth 60 FPS gameplay loop

---

## 🧠 OOP Design

| Concept | How I Applied It |
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

## 📁 Project Structure

```
Space-Invaders-OOP/
│
├── src/
│   ├── Space_Invaders2.cpp     # Main file — OOP version with header files
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

## 🎮 Controls

| Key | Action |
|:----|:-------|
| `A` or `←` | Move left |
| `D` or `→` | Move right |
| `Spacebar` | Shoot |
| `R` | Restart |
| `Esc` | Quit |

---

## ⚙️ How to Run

**Requirements**
- G++ with C++17 support
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

## 👨‍💻 Developer

**Kartar Singh**  
CS Student @ IBA Karachi  
[github.com/Kartarsingh123](https://github.com/Kartarsingh123)

---

## 📌 Why I Built This

I wanted to go beyond writing code that just works — I wanted to understand *why* you structure it the way you do. Building this game forced me to think about class design, inheritance chains, and how objects talk to each other. The jump from a 300-line single file to a clean multi-class architecture was the most valuable part of the whole project.
