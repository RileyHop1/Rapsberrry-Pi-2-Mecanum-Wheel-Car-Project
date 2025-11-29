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