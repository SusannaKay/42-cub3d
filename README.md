*This project has been created as part of the 42 curriculum by ebonacco and skayed*

---

## DESCRIPTION

**cube3D** is a minimalist 3D graphics engine written in C, inspired by the early FPS game *Wolfenstein 3D*.
The project implements a real-time rendering engine using the **raycasting algorithm**, simulating a 3D environment from a 2D map.

The engine parses a configuration file (`.cub`), loads textures, handles player movement, and renders walls using perspective projection.

This project focuses on:

- Implementing a **raycasting engine**
- Understanding **DDA (Digital Differential Analyzer)**
- Managing textures and wall projection
- Parsing structured configuration files
- Handling keyboard input and real-time rendering
- Managing memory manually in C

The final result is a first-person 3D visualization of a 2D map.

---

## INSTRUCTIONS

### Requirements

- Linux
- `gcc`
- `make`
- MiniLibX (included in the project)

### Clone the repository

```bash
git clone (repo link)
cd cube3D
```

### Compile

```bash
make
```

Available Makefile rules:

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

---

### Usage

Run the program with a valid `.cub` file:

```bash
./cube3D maps/map.cub
```

---

### Controls

| Key | Action |
|------|--------|
| W | Move forward |
| S | Move backward |
| A | Move left |
| D | Move right |
| ← → | Rotate camera |
| ESC | Exit |

---

### Technical Concepts

- Raycasting algorithm
- DDA line stepping
- Perspective projection
- Texture mapping
- Event-driven programming
- Manual memory management in C

---

## RESOURCES

- Lode's Raycasting Tutorial
  https://lodev.org/cgtutor/raycasting.html

- Permadi Raycasting Tutorial
  https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

- MiniLibX documentation

- Bresenham’s Line Algorithm

---

### Use of Artificial Intelligence

Artificial Intelligence was used exclusively as a learning support tool for:

- Clarifying raycasting theory
- Understanding projection mathematics
- Debugging logical issues
- Structuring documentation

AI was **not used to generate the final project code**, but only as an educational assistant.


