bool testTurnLeft() {
    std::cout << "Testing if can turn left: ";
    CarController* car = CarController::Instance();

    car->turnLeft(10.0);
    car->update();
    if (car->getDirection() == Direction::WEST) { // <-- should be WEST
        std::cout << "It passed\n";
        car->reset();
        return true;
    }
    std::cout << "It failed\n";
    car->reset();
    return false;
}

bool testTurnRight() {
    std::cout << "Testing if can turn right: ";
    CarController* car = CarController::Instance();

    car->turnRight(10.0);
    car->update();
    if (car->getDirection() == Direction::EAST) { // <-- should be EAST
        std::cout << "It passed\n";
        car->reset();
        return true;
    }
    std::cout << "It failed\n";
    car->reset();
    return false;
}

bool testTurnLeftTwice() {
    std::cout << "Testing if can turn left twice: ";
    CarController* car = CarController::Instance();

    car->turnLeft(10.0);
    car->update();
    car->turnLeft(10.0);
    car->update();

    if (car->getDirection() == Direction::SOUTH) { 
        std::cout << "It passed\n";
        car->reset();
        return true;
    }
    std::cout << "It failed\n";
    car->reset();
    return false;
}

bool testTurnRightTwice() {
    std::cout << "Testing if can turn right twice: ";
    CarController* car = CarController::Instance();

    car->turnRight(10.0);
    car->update();
    car->turnRight(10.0);
    car->update();

    if (car->getDirection() == Direction::SOUTH) { 
        std::cout << "It passed\n";
        car->reset();
        return true;
    }
    std::cout << "It failed\n";
    car->reset();
    return false;
}

bool testMoveForward() {
    std::cout << "Testing move forward: ";
    CarController* car = CarController::Instance();

    car->reset(); 
    car->moveForward(5.0);
    car->update();

    if (car->getYpos() == 5.0 && car->getXpos() == 0.0) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}

bool testMoveBackward() {
    std::cout << "Testing move backward: ";
    CarController* car = CarController::Instance();

    car->reset();
    car->moveBackward(3.0);
    car->update();

    if (car->getYpos() == -3.0 && car->getXpos() == 0.0) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}
bool testMoveForwardAfterRightTurn() {
    std::cout << "Testing move forward after right turn: ";
    CarController* car = CarController::Instance();

    car->reset(); 
    car->turnRight(10.0);
    car->update(); 
    car->moveForward(4.0);
    car->update();

    if (car->getXpos() == 4.0 && car->getYpos() == 0.0) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}

bool testMoveForwardAfterLeftTurn() {
    std::cout << "Testing move forward after left turn: ";
    CarController* car = CarController::Instance();

    car->reset(); 
    car->turnLeft(10.0);
    car->update(); 
    car->moveForward(2.0);
    car->update();

    if (car->getXpos() == -2.0 && car->getYpos() == 0.0) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}

bool testFullRotation() {
    std::cout << "Testing full rotation: ";
    CarController* car = CarController::Instance();
    car->reset();

    car->turnRight(10.0); car->update();
    car->turnRight(10.0); car->update();
    car->turnRight(10.0); car->update();
    car->turnRight(10.0); car->update();

    if (car->getDirection() == Direction::NORTH) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}

bool testStopPreventsMovement() {
    std::cout << "Testing stop prevents movement: ";
    CarController* car = CarController::Instance();
    car->reset();

    car->moveForward(5.0);
    car->stop();
    car->update();

    if (car->getYpos() == 0.0) {
        std::cout << "It passed\n";
        return true;
    }
    std::cout << "It failed\n";
    return false;
}




void runCarTests() {
    testTurnLeft();
    testTurnRight();
    testTurnLeftTwice();
    testTurnRightTwice();
    testMoveForward();
    testMoveBackward();
    testMoveForwardAfterRightTurn();
    testMoveForwardAfterLeftTurn();
    testFullRotation();
    testStopPreventsMovement();
}
