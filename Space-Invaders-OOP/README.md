# 🎮 Space Invaders — OOP C++ Game

![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue)
![Raylib](https://img.shields.io/badge/Library-Raylib-red)
![OOP](https://img.shields.io/badge/Concepts-OOP-green)
![IBA](https://img.shields.io/badge/Institute-IBA%20Karachi-yellow)

A Space Invaders inspired arcade game developed in **C++** using the **Raylib** graphics library.  
This project was created as part of my **second semester coursework at IBA Karachi**.  
It demonstrates practical implementation of **Object-Oriented Programming** principles in a complete game development project.

---

## 🚀 Features

- 🚀 Player-controlled spaceship
- 👾 Enemy alien grid (classic Space Invaders style)
- 🔫 Shooting mechanics (player lasers)
- 💥 Enemy attack system (alien bullets)
- 🎯 Collision detection
- 🏆 Score system (+10 per alien killed)
- ❤️ Lives system (3 lives)
- 🎉 You Win screen when all aliens are defeated
- 💀 Game Over screen when all lives are lost
- 🔄 Restart functionality (Press R)
- ⚡ Smooth 50 FPS gameplay loop

---

## 🧠 OOP Concepts Used

| Concept | How It Is Applied |
|---|---|
| **Encapsulation** | `position` and `speed` are `protected` in base class, accessed through getters |
| **Inheritance** | `Spaceship` and `Alien` inherit from `Entity`. `Laser` and `AllienBullets` inherit from `Entity` |
| **Polymorphism** | `Draw()` and `Update()` are `virtual` in `Entity`, overridden in every subclass |
| **Abstraction** | `Entity` is an abstract base class with pure virtual functions |
| **Modular Design** | Code split into separate `.h` header files for each class |

---

## 📁 Project Structure

```
Space-Invaders-OOP/
│
├── src/
│   ├── Space_Invaders2.cpp   # Main file (OOP version with .h files)
│   ├── Space_invaders.cpp    # Original single file version
│   ├── Entity.h              # Abstract base class
│   ├── Laser.h               # Player laser (inherits Entity)
│   ├── AllienBullets.h       # Alien bullet (inherits Entity)
│   ├── Alien.h               # Alien enemy (inherits Entity)
│   ├── Spaceship.h           # Player spaceship (inherits Entity)
│   ├── Game.h                # Main game class
│   ├── Rocket.png            # Spaceship sprite
│   └── alien_2.png           # Alien sprite
│
├── .vscode/
│   ├── tasks.json            # Build tasks
│   ├── launch.json           # Debug configurations
│   └── c_cpp_properties.json # IntelliSense config
│
└── README.md
```

---

## 🏗️ Class Hierarchy

```
Entity  (abstract base class)
│
├── Spaceship       (player — moves left/right, fires lasers)
├── Alien           (enemy — moves in formation, fires bullets)
├── Laser           (player bullet — moves up)
└── AllienBullets   (alien bullet — moves down)
```

---

## 🎮 Controls

| Key | Action |
|---|---|
| `A` or `←` | Move Left |
| `D` or `→` | Move Right |
| `Spacebar` | Shoot |
| `R` | Restart Game |
| `Esc` | Exit Game |

---

## ⚙️ How to Run

### Requirements
- C++17 compatible compiler (G++ recommended)
- [Raylib 5.5](https://www.raylib.com/) library installed
- Windows OS

### Compile & Run

```bash
# Compile
g++ -std=c++17 Space_Invaders2.cpp -o Space_Invaders2 -I. -lraylib -lopengl32 -lgdi32 -lwinmm

# Run
./Space_Invaders2
```

### Using VS Code
1. Open the `raylib_pacman` folder in VS Code
2. Press `Ctrl + Shift + B`
3. Select **"Build Space Invaders 2"**
4. Press `F5` and select **"Debug Space Invaders 2"**

---

## 👨‍💻 Developer

**Kartar Singh**  
Computer Science Student  
Institute of Business Administration (IBA), Karachi  
Spring 2026

---

## 📌 Project Purpose

This project was built to strengthen my understanding of **Object-Oriented Programming** by applying concepts in a real-time interactive game.  
It helped improve my skills in:
- Game development with Raylib
- OOP design and class hierarchy
- Modular programming with header files
- Logic building and collision detection

---

## 📚 Course

**CSE142 — Object Oriented Programming Techniques**  
Spring Semester 2026  
Institute of Business Administration, Karachi
