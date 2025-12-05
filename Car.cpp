#include "Car.h"
#include "Motor.h"
#include <iostream>

CarController* CarController::myInstance = nullptr;

Motor CarController::myMotorBackLeft(1, Direction::NORTH, 0);
Motor CarController::myMotorBackRight(2, Direction::NORTH, 0);
Motor CarController::myMotorFrontLeft(3, Direction::NORTH, 0);
Motor CarController::myMotorFrontRight(4, Direction::NORTH, 0);

Point CarController::myPos = Point(0, 0);

bool CarController::myTurning = false;

CarController::CarController() {
}

CarController* CarController::Instance() {
    //should force only one object to be within memory
    if (myInstance == nullptr) {
        myInstance = new CarController;
    }
    return myInstance;
}

CarController::~CarController() {
}

void CarController::moveForward(const float theSpeed) {
    myMotorBackLeft.setSpeed(theSpeed);
    myMotorBackRight.setSpeed(theSpeed);
    myMotorFrontLeft.setSpeed(theSpeed);
    myMotorFrontRight.setSpeed(theSpeed);
}

void CarController::moveBackward(const float theSpeed) {
    myMotorBackLeft.setSpeed(-theSpeed);
    myMotorBackRight.setSpeed(-theSpeed);
    myMotorFrontLeft.setSpeed(-theSpeed);
    myMotorFrontRight.setSpeed(-theSpeed);
}

void CarController::turnLeft(const float theSpeed) {
    myMotorBackLeft.stop();
    myMotorBackRight.setSpeed(theSpeed);
    myMotorFrontLeft.stop();
    myMotorFrontRight.setSpeed(theSpeed);

    myTurning = true;
}

void CarController::turnRight(const float theSpeed) {
    myMotorBackLeft.setSpeed(theSpeed);
    myMotorBackRight.stop();
    myMotorFrontLeft.setSpeed(theSpeed);
    myMotorFrontRight.stop();
    myTurning = true;
}

void CarController::stop() {
    myMotorBackLeft.stop();
    myMotorBackRight.stop();
    myMotorFrontLeft.stop();
    myMotorFrontRight.stop();
}

float CarController::getXpos() {
    return myPos.xPos;
}

float CarController::getYpos() {
    return myPos.yPos;
}

void CarController::setXpos(const float theX) {
    myPos.xPos = theX;
}

void CarController::setYpos(const float theY) {
    myPos.yPos = theY;
}

void CarController::update() {
    if (myTurning) {

        if (myMotorBackLeft.getSpeed() != 0) {
            myMotorBackLeft.turnRight();
            myMotorBackRight.turnRight();
            myMotorFrontLeft.turnRight();
            myMotorFrontRight.turnRight();
        } else {
            myMotorBackLeft.turnLeft();
            myMotorBackRight.turnLeft();
            myMotorFrontLeft.turnLeft();
            myMotorFrontRight.turnLeft();
        }

        myTurning = false;
    } 
    else {

        if (myMotorBackLeft.getDirection() == Direction::NORTH 
            || myMotorBackLeft.getDirection() == Direction::SOUTH) {

            switch(myMotorBackLeft.getDirection()) {
                case Direction::NORTH:
                    myPos.yPos += myMotorBackLeft.getSpeed();
                    break;
                case Direction::SOUTH:
                    myPos.yPos -= myMotorBackLeft.getSpeed();
                    break;
            }

        } else {
            switch(myMotorBackLeft.getDirection()) {
                case Direction::WEST:
                    myPos.xPos -= myMotorBackLeft.getSpeed();
                    break;
                case Direction::EAST:
                    myPos.xPos += myMotorBackLeft.getSpeed();
                    break;
            }
        }
    }

    stop();
}

Direction CarController::getDirection() {
    return myMotorBackLeft.getDirection();
}

void CarController::printDriection() {
    switch(myMotorBackLeft.getDirection()) {
        case Direction::SOUTH:
            std::cout << "South\n";
            break;
        case Direction::WEST:
            std::cout << "West\n";
            break;
        case Direction::NORTH:
            std::cout << "North\n";
            break;
        case Direction::EAST:
            std::cout << "East\n";
            break;
    }
}

void CarController::reset() {
    myMotorBackLeft.stop();
    myMotorBackRight.stop();
    myMotorFrontLeft.stop();
    myMotorFrontRight.stop();

    myPos.xPos = 0.0f;
    myPos.yPos = 0.0f;

    myMotorBackLeft.setDirection(Direction::NORTH);
    myMotorBackRight.setDirection(Direction::NORTH);
    myMotorFrontLeft.setDirection(Direction::NORTH);
    myMotorFrontRight.setDirection(Direction::NORTH);

    myTurning = false;
}
