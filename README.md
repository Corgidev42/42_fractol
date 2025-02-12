# Fract'ol - Fractal Viewer in C with MiniLibX

## 📌 Description
**Fract'ol** is a fractal visualization project written in **C**, using the **MiniLibX** graphics library. It allows you to display and dynamically explore several famous fractals:

- **Mandelbrot** 🌀
- **Julia** 🔷
- **Burning Ship** 🚢

Users can interact with the fractal by zooming, navigating, and modifying colors for an enhanced visual experience.

---

## 🎮 Features

- 🖥 **Real-time rendering** with MiniLibX
- 🎨 **Multiple color palettes** (Grayscale, Fire, Cool, Sunset, Ocean)
- 🔍 **Zooming** with the mouse scroll
- 🚀 **Navigation** with arrow keys
- 🔄 **Fractal reset**
- 🔢 **Iteration count modification** to adjust detail levels
- ❌ **Error handling and input validation**

---

## 🛠 Compilation and Execution

### 🔧 **Compilation**
Ensure **MiniLibX** is installed, then compile the project with:
```sh
make
```

### ▶️ **Execution**
Run the application with the desired fractal:
```sh
./fractol mandelbrot
./fractol julia <number1> <number2>
./fractol burning_ship
```
- `mandelbrot` : Displays the Mandelbrot set
- `julia <number1> <number2>` : Displays a Julia set with the specified parameters
- `burning_ship` : Displays the Burning Ship fractal

---

## ⌨️ Controls

| Key           | Action |
|--------------|------------------------------------------------|
| `ESC`       | Quit the application |
| `C`         | Change the color palette |
| `+` / `-`   | Modify the iteration count |
| `R`         | Reset the fractal |
| `Arrow Keys`| Move the view |
| `Mouse Scroll` | Zoom in/out |

---

## 📂 Project Structure

```
fractol/
├── src/
│   ├── app.c                # Application initialization and management
│   ├── color.c              # Color management
│   ├── error_handling.c     # Error handling and input parsing
│   ├── events.c             # Keyboard and mouse event handling
│   ├── fractal_iteration.c  # Fractal iteration algorithms
│   ├── render_fractal.c     # Fractal rendering and display
│   ├── app_utils.c          # Utility functions
├── includes/
│   ├── fractol.h            # Main header file
│   ├── color.h              # Color management
│   ├── events.h             # Event handling
│   ├── fractal_iteration.h  # Fractal algorithms
│   ├── render_fractal.h     # Graphics rendering
│   ├── app_utils.h          # Utility functions
├── Makefile                 # Project compilation
├── README.md                # Project documentation
```

---

## 📜 Author
- **vbonnard** (<vbonnard@student.42.fr>)

---

## 📌 Note
This project was developed as part of **42 School** and is based on **MiniLibX**.
If you encounter a bug or have suggestions, feel free to contribute! 🚀
