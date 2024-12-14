### Maze Project README

# Maze Project

This project is a maze-solving application written in C. It employs efficient algorithms and rendering tools to visualize maze generation and solution paths. The primary aim is to demonstrate algorithmic problem-solving with an emphasis on visualization.

---

## Features
- Maze generation using randomized algorithms.
- Visualization of maze paths and solving steps.
- Adjustable maze dimensions for custom challenges.
- High-performance rendering using efficient graphics libraries.

---

## Prerequisites
Ensure you have the following installed:
- **GCC Compiler** for compiling the C code.
- **SDL2 Library** (or any rendering library used) for rendering graphical output.
- **Linux-based system** (or equivalent environment).

---

## Installation and Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/jeremymordecai628/maze_project.git
   cd maze_project
   ```
2. Install required dependencies:
   ```bash
   sudo apt-get install libsdl2-dev  # For Linux users
   ```
3. Compile the code:
   ```bash
   gcc -o maze_solver maze_solver.c -lSDL2
   ```
4. Run the application:
   ```bash
   ./maze_solver
   ```

---

## File Structure
- **maze_solver.c**: Main logic for maze generation and solving.
- **rendering.c**: Contains rendering utilities for graphical output.
- **README.md**: Documentation.

---

## Contributing
Contributions are welcome! Please follow the standard Git workflow:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request with detailed changes.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---



