# Console Car Demo

A real-time **Windows console application** written in **C++** that demonstrates
smooth ASCII rendering, non-blocking keyboard input, and WAV audio playback.

The program renders an ASCII car that can be moved around the console window
using the arrow keys. Sound effects play on movement and on exit, and the
application handles screen boundaries.

---

## Features
- Real-time ASCII rendering in the Windows console
- Flicker-free output using double-buffered frame rendering
- Non-blocking keyboard input (arrow keys)
- Proper handling of console window boundaries
- WAV audio playback using the Windows Multimedia API
- Clean separation of source code and assets

---

## Controls
- **Arrow Keys** — Move the car
- **X** — Exit the application

---

## How to Run (Windows / Visual Studio)

1. Open **Visual Studio**
2. Create a new **C++ Console Application**
3. Replace the generated `main.cpp` with `src/main.cpp`
4. Ensure the `sounds/` folder exists at the project root
5. Set **Working Directory** to: `$(ProjectDir)`
6. Build and run the project (`F5`)

---

## Technologies Used
- C++
- Win32 Console API
- Windows Multimedia API (`PlaySound`)
- ASCII rendering techniques

---

## What I Learned
- Handling non-blocking keyboard input in console applications
- Implementing flicker-free rendering without using `system("cls")`
- Managing real-time loops and frame timing
- Playing WAV audio reliably on Windows
- Handling edge cases and screen boundaries safely
- Structuring a clean, professional GitHub repository

---

## Notes
This project is intended as a **technical demo** showcasing low-level console
rendering and input handling on Windows, rather than a full game.
