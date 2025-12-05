#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Car.h"
#include <string>
#include <iostream>

class Simulator {
public:
    // create simulator using existing CarController
    Simulator(CarController* car);

    // main simulation loop
    void run();

    void drawMap();

private:
    CarController* car; // pointer to singleton

    void interactiveMode();

    // Run a demo scripted path
    void runDemoPath();
};

#endif
