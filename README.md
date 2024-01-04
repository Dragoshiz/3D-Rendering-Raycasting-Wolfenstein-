# 3D Rendering Raycasting Wolfenstein

![Screenshot from 2024-01-03 11-46-41](https://github.com/Dragoshiz/3D-Rendering-Raycasting-Wolfenstein-/assets/61502947/1e838b78-1d9d-4096-afc2-e996f8509eea)

## Introduction
This project is a 3D rendering engine built using raycasting techniques, inspired by classic games like Wolfenstein 3D. It's designed to demonstrate the basics of 3D graphics in a simple and understandable way.

## Features
- Raycasting-based 3D rendering
- Simple map design and rendering

## Prerequisites
Before installing, make sure your system has the necessary libraries. Run:
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
## Installation
1. Clone the repository:
```
git clone https://github.com/Dragoshiz/3D-Rendering-Raycasting-Wolfenstein-
```
2. Navigate to the project directory:
```
cd [project-directory]
```
3. Compile the project:
```
make
```
## Customizing the Map

### Map Design
![Screenshot from 2024-01-03 11-56-59](https://github.com/Dragoshiz/3D-Rendering-Raycasting-Wolfenstein-/assets/61502947/5befa6b9-7fdf-4937-b3a2-66ad092a47f1)  
The map is represented by a grid of characters where each character has a specific meaning:
- `1` represents a wall block.
- `0` represents an empty space that players can move through.

To customize the layout of your map, edit the grid in the configuration file (or where the map is defined) using `1` and `0` to design the walls and open spaces. Here's an example of a simple map layout:<br>
```
1111111111111111111111111
1000000000000000000000001
1011000111110111111100111
1001000000110000000000001
1111111110111111111111111  
```
(The map has to have closed walls)


### Changing Wall Textures
To modify the appearance of the walls, you can change the paths to the texture files in the configuration. Each direction (`NO`, `EA`, `WE`, `SO`) represents a wall facing a cardinal direction (North, East, West, South), and each line in the configuration file defines the texture for that direction.

For example:
- `NO` stands for North-facing walls. To change the texture, replace the file path after `NO` with the path to your new texture.
- `EA` stands for East-facing walls, and so on.

Here's the syntax for changing wall textures:<br>
```
NO path/to/your/northwall_texture.xpm
EA path/to/your/eastwall_texture.xpm
WE path/to/your/westwall_texture.xpm
SO path/to/your/southwall_texture.xpm
```
Replace `path/to/your/texture.xpm` with the actual path to the `.xpm` image you want to use as the texture for that direction's walls.

### Floor and Ceiling Colors
You can also customize the floor and ceiling colors using RGB values:

- `F` stands for the floor color, followed by its RGB values.
- `C` stands for the ceiling color, followed by its RGB values.

For example:
```
F 128,128,128 # This sets the floor color to a grey shade.
C 50,50,255 # This sets the ceiling color to a shade of blue.
```
Change these values to any RGB color combination to customize the appearance of the floor and ceiling in your game.

## Usage
Run executable with the map design of your choice as argument (has to have .cub extension):
```
./cub3D big_map.cub
```
## Acknowledgments
Special thanks to my partner for this project:
- [Valentin](https://github.com/minthe)
