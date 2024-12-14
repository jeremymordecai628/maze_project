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

# Collaboration Supplier

---

## Overview
This web-based project is a supplier collaboration system built with PHP. It enables streamlined communication between procurement employees and suppliers, enhancing data management for company devices and procurement workflows.

---

## Features
- Supplier registration and management.
- Dynamic dropdown fields for procurement employee selection.
- Device inventory and collaboration workflows.
- Secure session handling and authentication.

---

## Prerequisites
Ensure you have the following installed:
- **PHP 7.4+**.
- **MySQL Database**.
- A web server like **Apache** or **Nginx**.
- **phpMyAdmin** (optional for database management).

---

## Installation and Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/jeremymordecai628/collaboration_supplier.git
   cd collaboration_supplier
   ```
2. Configure your database:
   - Import the `supplier_collaboration.sql` file into MySQL.
   - Update database credentials in `config.php`.

3. Deploy to your server:
   - Place files in your web server’s root directory (e.g., `/var/www/html/`).
   - Access the application via `http://localhost/collaboration_supplier`.

---

## File Structure
- **index.php**: Main entry point for the system.
- **config.php**: Database connection configuration.
- **dashboard.php**: Dashboard for managing suppliers and devices.
- **styles/**: CSS files for design.

---

## Contributing
Feel free to open issues or create pull requests for improvements. All contributions should follow standard PHP practices.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

