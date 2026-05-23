<div align="center">

```
 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗
██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝
```

*My first RayCaster with miniLibX* — a Codam project

![C](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Codam](https://img.shields.io/badge/school-Codam-black?style=flat-square)
![Graphics](https://img.shields.io/badge/project-cub3D-orange?style=flat-square)
![MLX42](https://img.shields.io/badge/library-MLX42-red?style=flat-square)

</div>

---

## 📖 About

**cub3D** is a 3D maze renderer built in C using ray-casting — the same technique behind the original Wolfenstein 3D. The project renders a first-person perspective view of a maze defined by a `.cub` scene file, complete with directional wall textures, floor/ceiling colors, and smooth keyboard navigation.

---

## ✨ Features

- 🧱 **Ray-casting engine** — renders a 3D perspective from a 2D map in real time
- 🖼️ **Directional wall textures** — different textures for North, South, East, West walls
- 🎨 **Configurable floor & ceiling colors** via the `.cub` scene file
- 🗺️ **Map validation** — detects unclosed maps, invalid characters, and missing config
- 🕹️ **Smooth controls** — WASD movement + arrow key rotation
- ❌ **Clean exit** — ESC key and window close button both exit properly

### 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Look left |
| `→` | Look right |
| `ESC` | Quit |

---

## 🗺️ Scene File Format (`.cub`)

The program takes a `.cub` file as its only argument. Here's a valid example:

```
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 225,30,0

111111
100N01
101001
100001
111111
```

### Elements

| Identifier | Description |
|------------|-------------|
| `NO` | Path to the North wall texture |
| `SO` | Path to the South wall texture |
| `WE` | Path to the West wall texture |
| `EA` | Path to the East wall texture |
| `F r,g,b` | Floor color (RGB 0–255) |
| `C r,g,b` | Ceiling color (RGB 0–255) |

### Map Rules

- Valid characters: `0` (empty), `1` (wall), `N` `S` `E` `W` (player spawn + orientation)
- The map must be **fully enclosed by walls**
- The map must be the **last element** in the file
- Spaces are valid map characters and must be handled
- Any misconfiguration exits with `Error\n` and an explicit message

---

## 🏗️ Project Structure

```
cub3D/
├── includes/          # Header files (+ MLX42 headers copied at build time)
├── src/
│   ├── main.c
│   ├── game/          # Game loop and controls
│   ├── parsing/       # .cub file parsing and config
│   ├── validation/    # Map and input validation
│   ├── raycasting/    # Ray math and casting logic
│   ├── render/        # Image rendering, textures, draw utils
│   └── utils/         # Memory, math, flood fill, cleanup, init
├── libft/             # Custom C library (submodule)
├── MLX42/             # Graphics library (submodule)
└── Makefile
```

---

## 🚀 Getting Started

### Prerequisites

- `gcc` / `cc`
- `make`
- `cmake`
- `glfw`

### Build & Run

```bash
# Clone with submodules
git clone --recurse-submodules https://github.com/SupaFlava/Cub3d.git
cd cub3D

# Compile (also builds libft and MLX42 automatically)
make

# Run with a scene file
./cub3D maps/your_map.cub
```

### Makefile Rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Build everything (libft, MLX42, cub3D) |
| `make clean` | Remove object files |
| `make fclean` | Remove object files + binary + MLX42 build |
| `make re` | Full recompile |

---

## 🍎 Mac Silicon (M1/M2/M3) Fix

MLX42 on Apple Silicon requires **GLFW** installed via Homebrew and a few Makefile tweaks to link correctly.

**1. Install dependencies**
```bash
brew install glfw cmake
```

**2. In the Makefile, uncomment the Apple Silicon lines**

There are three commented-out lines marked with `# this is for apple silicon` — uncomment them:

```makefile
# In CFLAGS, uncomment:
-I$(BREW_PREFIX)/opt/glfw/include

# In LDFLAGS, uncomment:
-framework Cocoa -framework OpenGL -framework IOKit
```

**3. Build**
```bash
make re
```

> The `BREW_PREFIX` variable already points to `/opt/homebrew` — the default Homebrew path on Apple Silicon. If your Homebrew is installed elsewhere, update that variable.

---

## ⚠️ Notes

- MLX42 is used instead of the original miniLibX for better cross-platform support
- Both libft and MLX42 are pulled in as **git submodules** and built automatically on `make`
- CMake output is suppressed during build for a cleaner terminal — remove the `> /dev/null` redirects in the Makefile temporarily if you need to debug build issues

---

## 👥 Authors

> Built as a team project at **Codam**

- [@SupaFlava](https://github.com/SupaFlava)
- [@W0ffel](https://github.com/W0ffel)
