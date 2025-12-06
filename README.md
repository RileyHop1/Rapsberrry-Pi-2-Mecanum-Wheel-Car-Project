# Rapsberrry-Pi-2-Mecanum-Wheel-Car-Project

## How to compile and run the project

- To compile run:
```bash
g++ -std=c++14 *.cpp -o CarSimulator
```
- Next to run the project do:
```Bash
./CarSimulator
```

## Description

This project implements a complete C++ software driver and simulator for a Raspberry Pi 2 Mecanum‑wheel car. The goal is to abstract the car’s hardware (motors, power stage, and camera) into clean, reusable C++ classes, and then provide a text‑based simulator so the car logic can be tested without physical hardware.

| File | Layer | Description |
| :--- | :--- | :--- |
| **`Motor.h` / `Motor.cpp`** | Driver | Defines the **Motor class**, abstracting a single DC motor. It handles **speed**, **direction**, and **stop** commands (the lowest layer of hardware interaction). |
| **`Camera.h` / `Camera.cpp`** | Driver | Defines the **Camera class**, simulating basic camera functionality like capturing a frame or starting/stopping streaming. |
| **`Car.h` / `Car.cpp`** | Controller | Defines the **Car class**. It uses four `Motor` objects (composition) and one `Camera` object to implement high-level movement commands (e.g., `moveForward`, `turnLeft`) based on **Mecanum-wheel logic**.  |
| **`Simulator.h` / `Simulator.cpp`** | Simulator | Defines the **Simulator class**. It tracks the car's virtual state: $\text{x, y}$ coordinates and $\text{orientation}$ on a 2D grid. It updates the position based on the commands issued by the `Car`. |
| **`main.cpp`** | UI/Entry Point | Contains the main program loop and a **text-based menu interface**. It handles user input, validates commands, and drives the interaction between the `Car` and the `Simulator`. |


## Reflection 

### Riley Hopper:
I don't really think this project was that challenging; most of the things that I did, I had done before within C++ and other programming languages. The part that was the most difficult was the direction code, I orignally put all the code for the cars position and rotation within the car class, (We later moved it over to the simulator to meet the project requirements) making the rotation code took me a little bit to workout, I had to move to scratch paper and breakdown how I wanted the logic to flow. I also had to make a few helper functions to help it work.

I didn't really learn anything new about software design or C++ from this project. I had already taken TCS 360 beforehand, and within that class, I wrote a 2D dungeon crawler in C++ using the SDL3 library, so I already have some experience working on software projects and 
C++. All the things we did for this project in C++ kind of just fall under the scope of things I have already done.

## Testing

### Test 1: 
To test movement I pressed D to rotate the car to the right twice and  w to move it forward. I entered in a speed of 10 and the cars y position changed to -10, I then entered in s with a speed of 10 to see if it would move back to the (0,0) and it did.

### Test 2:

