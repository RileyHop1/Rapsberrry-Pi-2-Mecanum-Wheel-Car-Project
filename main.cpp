#include <iostream>
#include "Car.h"
#include "Simulator.h"
#include "Camera.h"

int main() {
    std::cout << "=== Smart Car Simulator ===\n";

    // Create CarController singleton
    CarController* myCar = CarController::Instance();

    // Start camera streaming
    myCar->getCamera().startStreaming();

    // Create simulator using singleton
    Simulator sim(myCar);

    char command;
    float value;

    bool running = true;
    
    while (running) {
    sim.drawMap();

    std::cout << "=== Car Menu ===\n";
    std::cout << "w : Move Forward\n";
    std::cout << "s : Move Backward\n";
    std::cout << "a : Turn Left\n";
    std::cout << "d : Turn Right\n";
    std::cout << "x : Stop\n";
    std::cout << "c : Capture Camera Frame\n";
    std::cout << "r : Reset Car\n";
    std::cout << "z : Quit\n";

    // Validate command input
    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Please enter a command.\n";
            continue;
        }
        command = std::tolower(command);
        break;
    }

    switch (command) {
        case 'w':
        case 's':
        case 'a':
        case 'd':
            // Validate numeric input for speed
            while (true) {
                std::cout << "Enter speed: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid number! Try again.\n";
                    continue;
                }
                break;
            }
            if (command == 'w') myCar->moveForward(value);
            else if (command == 's') myCar->moveBackward(value);
            else if (command == 'a') myCar->turnLeft(value);
            else if (command == 'd') myCar->turnRight(value);
            myCar->update();
            break;
        case 'x':
            myCar->stop();
            break;
        case 'c':
            myCar->getCamera().captureFrame(myCar->getXpos(), myCar->getYpos());
            break;
        case 'r':
            myCar->reset();
            break;
        case 'z':
            running = false;
            break;
        default:
            std::cout << "Invalid command! Try again.\n";
            break;
    }
}

    myCar->getCamera().stopStreaming();
    std::cout << "Simulation ended.\n";
    return 0;
}
