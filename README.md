# C-RayTracer [miniRT]

A minimalist raytracer in C powered by MLX42. It parses `.rt` scene files and renders simple 3D scenes with ambient and diffuse lighting in real time.

---

## Description

This is a stripped-down raytracer implementing the mandatory part of the miniRT project from the 42 Network. It reads a scene description (`.rt`), builds basic geometric objects (plane, sphere, cylinder), and displays the result in an adjustable MLX42 window. The project demonstrates low-level graphics, vector math, file parsing in C, and following the 42 Norm C coding standard.

Made with [@jackwaddington](https://github.com/jackwaddington) on his repo: https://github.com/jackwaddington/minirt

## Features

* **Geometric Primitives:** Plane, Sphere, Cylinder
* **Lighting:** Ambient and diffuse lighting with single point light source
* **Transformations:** Translation for all objects; rotation for planes, cylinders, and camera
* **Parsing:** Robust `.rt` parser enforcing strict order and value ranges
* **Window Management:** Resizable MLX42 window; clean exit on ESC or window close
* **Memory Safety:** All allocations are freed on exit

## Prerequisites

* C compiler (gcc)
* GNU make
* Standard C libraries and math library

## Installation

```bash
# Clone miniRT and build
git clone https://github.com/BrunoPosa/C-RayTracer miniRT
cd miniRT
make
```

## Usage

```bash
./miniRT scenes/2_just_shadows.rt
```

* **ESC**: Exit program
* **Window close**: Clean exit
* **Resize window**: Image scales to fit

## Scene File Format

Each line defines one element, in any order. Elements with single identifiers (`A`, `C`, `L`) appear once only.

* **Ambience:** `A <ratio> <R,G,B>`
* **Camera:** `C <pos> <orient> <FOV>`
* **Light:**  `L <pos> <brightness> <R,G,B>`
* **Sphere:** `sp <center> <diameter> <R,G,B>`
* **Plane:**  `pl <point> <normal>   <R,G,B>`
* **Cylinder:** `cy <center> <axis> <diameter> <height> <R,G,B>`

*Example:* `scenes/3_inside_objects.rt`

```text
C 0,6,-5  0,-0.6,0.8  110  
L 0,4,0 0.7 255,255,255
A 0.5 255,255,255
# cylinders
cy 4,1,4  0,0.6,-0.8  2  2  255,0,0
cy 0,2,6   0.6,0,-0.8  2  3  0,0,255
cy 0,0,-6  0,0,1  15  12  0,255,0
cy 0,-2,5  0,0.6,0.8  2  2.5  0,255,127
cy -4,-3,3  0,0.6,-0.8  2  3  255,127,255
# spheres
sp 0,0,0 2 255,255,0
sp 0,-1,0 1 255,0,0
sp 0,2,2 1 255,0,127
# planes
pl 0,-5,5    0,-1,0   66,135,245
```


## Example scene 3_inside_objects.rt

![Rendered Scene 3_inside_objects.rt](./image.png)

## Next Steps

* Add reflections, shadows, and specular highlights
* Implement bonus objects: square, triangle, cube
* Optimize with bounding volumes and multithreading

