# Maze Solver Using C

## Project Description

The **Maze Solver** is a C-based application designed to solve mazes using various pathfinding algorithms. 
It allows users to input a maze, select a preferred algorithm, and displays the optimal path to the goal. 
The project focuses on exploring graph traversal techniques to find the shortest or most efficient route through the maze.

The implementation uses a menu-driven interface for simplicity and provides clear feedback on the chosen algorithm's behavior. 
This project is perfect for learning the inner workings of popular pathfinding algorithms and exploring their real-world applications.

---

## Features

- Multiple Pathfinding Algorithms**:
  - Depth First Search (DFS): Explores paths in a depth-wise manner, useful for traversing all possible routes.
  - Breadth First Search (BFS): Ensures the shortest path in an unweighted maze by exploring all nodes level by level.
  - A*: Uses a heuristic-based approach to find the optimal path quickly.
  - Dijkstra’s Algorithm: Guarantees the shortest path in weighted mazes using cost-based traversal.
- Dynamic Input: Users can input custom maze structures or use default examples.
- User-Friendly Interface: Menu-driven input for selecting algorithms and viewing results.
- Visual Representation: Displays the maze and the optimal path in a clear, understandable format.

---

## How It Works

1. Maze Representation:
   - The maze is represented as a 2D grid where:
     - `0` represents open paths.
     - `1` represents walls.
     - `S` is the start point.
     - `E` is the endpoint.
2. Algorithm Selection:
   - Users select one of the provided algorithms from the menu.
3. Execution:
   - The selected algorithm processes the maze, determines the path, and returns the result.
4. Output:
   - The solution displays the maze with the shortest path marked.

---

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Maze-Solver.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Maze-Solver
   ```
3. Compile the program:
   ```bash
   gcc maze_solver.c -o maze_solver
   ```
4. Run the program:
   ```bash
   ./maze_solver
   ```
5. Follow the on-screen instructions:
   - Enter the maze dimensions and structure (or use the default).
   - Select an algorithm to solve the maze.
   - View the result, including the optimal path.

---

## Technologies and Concepts Used

- Programming Language: C
- Data Structures:
  - Graphs
  - Queues (for BFS)
  - Priority Queues (for A* and Dijkstra)
  - Stacks (for DFS)
- Pathfinding Algorithms:
  - DFS, BFS, A*, Dijkstra
- Dynamic Memory Allocation for maze storage and traversal.

---

## Example Input/Output

### **Input Maze**:
```plaintext
S 0 1 0 0
0 0 1 0 1
1 0 0 0 0
1 1 1 1 E
```

### **Output Maze (Using BFS)**:
```plaintext
S * 1 0 0
0 * 1 0 1
1 * * * *
1 1 1 1 E
```

---

## Use Cases

- Educational: Understand and compare different pathfinding algorithms.
- Maze Games: Build logic for solving maze-based games.
- Robotics: Apply to navigation algorithms in robotic systems.

---

## Future Enhancements

- Add graphical visualization using a library like SDL or OpenGL.
- Support for 3D mazes or dynamic mazes with obstacles.
- Implementation of real-time solving for larger mazes.
- Add more algorithms like Greedy Best-First Search or Bidirectional Search.

---

## Contributing

Contributions are welcome! If you have ideas for new features or optimizations, feel free to:
- Fork the repository.
- Make your changes.
- Submit a pull request.

---

## License

This project is licensed under the MIT License. Feel free to use it as a learning resource or extend it for your own projects.
