# cub3D

A raycasting engine in C, in the spirit of Wolfenstein 3D. Renders a first-person view of a 2D map defined in a custom `.cub` file format, using [MiniLibX](https://github.com/42Paris/minilibX-linux) for windowing and pixel drawing.

42 School project.

## Features

- Raycasting-based 3D rendering of a 2D grid map
- Textured walls, with a different texture per cardinal direction (north/south/east/west)
- Solid-color floor and ceiling
- Smooth movement (`W`/`A`/`S`/`D`) and camera rotation (arrow keys)
- Full `.cub` map parser with validation (closed map, valid characters, single player spawn, etc.)

## Requirements

- Linux with `gcc`/`cc`, `make`
- X11 and Xext development libraries (`libxext-dev`, `libx11-dev`)
- `libbsd-dev`

## Build

```sh
make
```

This builds `libft`, the bundled MiniLibX, and links the final `cub3D` binary. Other targets:

```sh
make clean   # remove object files
make fclean  # remove object files and the binary
make re      # fclean + all
```

## Usage

```sh
./cub3D maps/subject_map.cub
```

### Controls

| Key           | Action           |
| ------------- | ---------------- |
| `W` / `A` / `S` / `D` | Move forward / left / back / right |
| `←` / `→`     | Rotate camera left / right |
| `Esc` / close window | Quit |

## Map format (`.cub`)

A `.cub` file has two sections: configuration lines, then the ASCII map grid.

```
NO textures/wolfenstein/grey_stone.xpm
SO textures/wolfenstein/purple_stone.xpm
WE textures/wolfenstein/red_brick.xpm
EA textures/wolfenstein/wood.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        11000001110101000000N0111
        1111111111111111111111111
```

- `NO`, `SO`, `WE`, `EA` — paths to the north/south/west/east wall textures (`.xpm`)
- `F` — floor color as `R,G,B`
- `C` — ceiling color as `R,G,B`
- Map grid — `0` is walkable floor, `1` is a wall, space is void (must be surrounded so the map stays enclosed), and `N`/`S`/`E`/`W` marks the player's spawn point and facing direction

Sample maps for testing are in [maps/](maps/).

## Project layout

```
include/       cub3d.h — shared types and constants
src/
  init/        window/game setup, main loop, cleanup
  parsing/     .cub file parsing (config + map)
  map/         map validation, input handling, movement
  render/      raycasting and drawing
  utils/       small helpers (timing, misc)
libft/         custom libc + get_next_line + ft_printf
minilibx-linux/  bundled MiniLibX graphics library
maps/          sample .cub maps
textures/      sample wall/sprite textures
```
