# Bus Stop 3D Graphics

A 3D interactive bus stop simulation built with C++ and OpenGL. The scene features a detailed bus stop shelter with a bus, road, footpath, and surrounding grass, all rendered with textures and interactive camera controls.

## What It Does

The program renders a 3D scene containing:

- **Bus Stop Shelter** – A shelter with two side walls, a roof, a forward-slanting shade, and a stop sign on a stand.
- **Bus** – A red bus parked at the stop, complete with front and back wheels, passenger windows with stripes, a door, a roof, and bumper.
- **Environment** – A textured road, a raised footpath/pavement, and grass areas on both sides of the road.

The camera can be freely positioned and the entire scene can be rotated interactively using the keyboard and mouse.

## Technical Details

| Detail | Value |
|---|---|
| Language | C++ |
| Graphics API | OpenGL (Legacy/Fixed-Function Pipeline) |
| Windowing / Input | GLUT (freeglut / glut32) |
| Utilities | GLU (projection, look-at), GLAUX (BMP texture loading) |
| IDE / Build system | Code::Blocks with MinGW/GCC |
| Project file | `Bus_Stand_3D.cbp` |
| Entry point | `main.cpp` |

### Libraries Used

- `opengl32` – Core OpenGL rendering
- `glu32` – `gluPerspective`, `gluLookAt`
- `glut32` – Window creation, display loop, keyboard/mouse callbacks
- `glaux` – `auxDIBImageLoad` for loading BMP textures
- `winmm`, `gdi32` – Windows system libraries required by the above

### Textures

The following BMP texture files must be present in the executable's directory (`bin/Debug/` or `bin/Release/`) at runtime:

| File | Used for |
|---|---|
| `staircase12.bmp` | Footpath / pavement surface |
| `wall.bmp` | Bus stop walls, roof, and shade |
| `road.bmp` | Road surface |
| `grass.bmp` | Grass areas |
| `crest.bmp` | (Loaded, reserved) |
| `bus.bmp` | (Loaded, reserved) |
| `window1.bmp` | (Loaded, reserved) |

> **Note:** The texture paths are currently hard-coded to an absolute Windows path inside `LoadGLTextures()`. Before running, update those paths in `main.cpp` to match your local directory layout, or place the BMP files in the same directory as the executable and use relative paths.

### Key Functions

| Function | Description |
|---|---|
| `init()` | Sets background colour, projection, and loads textures |
| `display()` | Main render loop – sets perspective, applies camera and rotation, draws the scene |
| `busStop()` | Draws the bus stop shelter, shade, stop sign, and stands |
| `bus()` | Assembles and draws the complete bus |
| `quad()` | Draws the road, footpath, and grass terrain |
| `my_keyboard()` | Handles letter key presses for preset camera views |
| `specialKeys()` | Handles arrow keys for free camera movement |
| `mouse()` | Handles mouse buttons to start/stop rotation |

## How to Run

### Prerequisites

- **Windows** (the project uses Windows-specific headers and `glaux`)
- [Code::Blocks](https://www.codeblocks.org/) with the bundled MinGW toolchain
- OpenGL, GLU, GLUT, and GLAUX libraries (included with MinGW or available as separate packages)

### Steps

1. **Clone the repository**

   ```bash
   git clone https://github.com/Tahmid46/Bus-Stop-3D-Graphics.git
   cd Bus-Stop-3D-Graphics
   ```

2. **Add texture files**

   Copy the required BMP texture files (listed above) into the `bin/Debug/` directory, or update the paths in `LoadGLTextures()` inside `main.cpp` to point to the actual location of your textures.

3. **Open the project in Code::Blocks**

   Open `Bus_Stand_3D.cbp` in Code::Blocks.

4. **Build the project**

   Select **Build → Build** (or press `Ctrl+F9`) to compile the project.

5. **Run the executable**

   Select **Build → Run** (or press `Ctrl+F10`). A window titled **Bus Stop** (800 × 600) will open showing the 3D scene.

### Controls

| Input | Action |
|---|---|
| `f` | Front view |
| `b` | Back view |
| `l` | Left view |
| `r` | Right view |
| `t` | Top view |
| `m` | Bottom view |
| `←` / `→` Arrow keys | Move camera left / right |
| `↑` / `↓` Arrow keys | Zoom in / zoom out |
| Left mouse button | Rotate scene continuously left |
| Right mouse button | Rotate scene continuously right |
| Middle mouse button | Stop rotation |
