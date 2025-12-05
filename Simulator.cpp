/*
Author: Erik Babonis and Rylee Hopper
Project 2 
Provides the terminal-based simulator, including map drawing and menu interactions.
*/

#include "Simulator.h"
#include <thread>
#include <chrono>
#include <cmath>

// Size of map
static const int MAP_WIDTH  = 21;
static const int MAP_HEIGHT = 21;

// Convert world coordinates to map grid coordinates
void worldToMap(double x, double y, int& outRow, int& outCol)
{
    int centerRow = MAP_HEIGHT / 2;
    int centerCol = MAP_WIDTH / 2;

    outRow = centerRow - static_cast<int>(std::round(y));
    outCol = centerCol + static_cast<int>(std::round(x));
}

Simulator::Simulator(CarController* theCar) : car(theCar) {}

void Simulator::drawMap()
{
    int row = 0;
    int col = 0;
    worldToMap(car->getXpos(), car->getYpos(), row, col);

    std::cout << "\x1B[2J\x1B[H"; // clear screen

    std::cout << "Car Simulator\n";
    std::cout << "-------------\n";
    std::cout << "Pose: (x = " << car->getXpos() << ", y = " << car->getYpos() << ")\n\n";

    std::cout << "Map Legend: C = car, . = empty\n\n";

    for (int r = 0; r < MAP_HEIGHT; r++) {
        for (int c = 0; c < MAP_WIDTH; c++) {
            if (r == row && c == col) std::cout << 'C';
            else std::cout << '.';
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Simulator::runDemoPath()
{
    using namespace std::chrono_literals;

    drawMap();
    std::this_thread::sleep_for(800ms);

    car->moveForward(3.0);
    car->update();
    drawMap();
    std::this_thread::sleep_for(800ms);

    car->turnRight(1.0);
    car->update();
    drawMap();
    std::this_thread::sleep_for(800ms);

    car->moveBackward(2.0);
    car->update();
    drawMap();
    std::this_thread::sleep_for(800ms);

    car->turnLeft(1.0);
    car->update();
    drawMap();
    std::this_thread::sleep_for(800ms);

    car->stop();
    drawMap();
    std::this_thread::sleep_for(800ms);
}

void Simulator::interactiveMode()
{
    char cmd = ' ';
    float value = 0.0f;

    while (true) {
        drawMap();

        std::cout << "Commands:\n";
        std::cout << "  w : forward\n";
        std::cout << "  s : backward\n";
        std::cout << "  a : turn left\n";
        std::cout << "  d : turn right\n";
        std::cout << "  x : stop\n";
        std::cout << "  z : quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;
        if (!std::cin) return;
        if (cmd == 'z') break;

        if (cmd == 'x') {
            car->stop();
            continue;
        }

        std::cout << "Enter value: ";
        std::cin >> value;
        if (!std::cin) return;

        switch (cmd) {
            case 'w': car->moveForward(value); break;
            case 's': car->moveBackward(value); break;
            case 'a': car->turnLeft(value); break;
            case 'd': car->turnRight(value); break;
            default: break;
        }

        car->update();
    }
}

void Simulator::run()
{
    std::cout << "Run demo path? (y/n): ";
    char ans;
    std::cin >> ans;
    if (ans == 'y' || ans == 'Y') {
        runDemoPath();
    } else {
        interactiveMode();
    }
}
