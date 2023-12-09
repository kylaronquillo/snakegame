# snakegame
Console-Based Snake Game Project for CSDC103 Data Structures and Algorithms

PROGRAMMING PROJECT
SNAKE GAME

Objective
Implement the classic Snake game in C++ using various data structures and algorithms.

Requirements
Linked Lists
Use a linked list to represent the snake's body.
Implement functions to add a new body part when the snake eats food and remove the tail when moving.

Arrays
Create a 2D array to represent the game grid.
Initialize the grid with empty cells and update it with the snake's body and food positions.

Stacks
Use a stack to manage the snake's movements.
Push the new head position onto the stack and pop the tail position when moving.

Queues
Implement a queue to handle food placement.
Enqueue random positions for food, ensuring they do not overlap with the snake.

Graphs
Represent the game as a graph where each cell is a node.
Use graph traversal algorithms for collision detection and checking valid movements.

Game Mechanics
1. The snake moves through the grid, growing longer as it eats food.
   - Control the snake's direction using arrow keys.
   - Update the snake's position based on its current direction.

2. Implement collision detection for the snake:
   - Check for collisions with the game borders.
   - Detect collisions with the snake's own body.

3. Randomly place food on the grid:
   - Ensure the food does not appear on the snake's body.
   - Update the score when the snake eats the food.

4. Implement game over conditions:
   - End the game if the snake collides with the borders or itself.
Additional Challenges (Optional)
1. Implement different levels with varying speeds:
   - Gradually increase the snake's speed as the player advances.

2. Add obstacles that the snake must navigate around:
   - Create barriers on the grid that the snake cannot pass through.

3. Include power-ups that affect the snake's behavior:
   - Introduce special food items that provide temporary benefits or challenges.

User Interface
Design a simple console-based interface for the game. Display the current score, level, and other relevant information.
