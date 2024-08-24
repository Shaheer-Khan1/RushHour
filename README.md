# Taxi Game Simulation using GLUT

## Overview
This project is a simulation of a taxi game created using GLUT functions. The game features a taxi navigating a grid-based board, picking up and dropping off passengers, and avoiding obstacles. The game includes elements such as intelligent car movement, random positioning of obstacles and passengers, and a dynamic board that changes based on the player’s actions.

## Features
- **Dynamic Board Design:** A grid-based board with roads, buildings, and obstacles.
- **Player Control:** The player can control the taxi using arrow keys to move in four directions.
- **Passenger Pickup/Drop-off:** The player can pick up passengers by stopping adjacent to them and drop them off at a randomly assigned valid destination.
- **Intelligent Car Movement:** Other cars on the board move intelligently, avoiding obstacles and not colliding with buildings.
- **Random Elements:** Obstacles, passengers, and destinations are randomly positioned on the board.
- **Difficulty Scaling:** The number of cars and their speed increase as the player successfully drops off passengers.

## Gameplay Instructions
1. **Movement:** Use the arrow keys to move the taxi around the board.
2. **Pickup:** Stop next to a passenger and press the spacebar to pick them up.
3. **Drop-off:** Drive the passenger to their highlighted destination and press the spacebar to drop them off.
4. **Objective:** Successfully drop off as many passengers as possible while avoiding collisions with other cars and obstacles.

## Key Functionalities
- **Menu System:** Displays taxi choices and allows the player to enter their name.
- **Score Recording:** Records the total score and increases the difficulty as the game progresses.
- **Dynamic Obstacles:** Includes random placement of obstacles, buildings, and passengers to keep the game challenging.
- **Intelligent AI:** Cars move intelligently, avoiding static obstacles and other cars.
