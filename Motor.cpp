#include "Motor.h"





Motor::Motor(const int theId, const Direction theDir,
    const int theSpeed) : myId(theId), myDirection(theDir), myCurrentSpeed(theSpeed) {
    
    //We don't need anything here.
}

void Motor::setSpeed(const float theSpeed) {
    this->myCurrentSpeed = theSpeed;
}


void Motor::setDirection(const Direction theDirection) {
    this->myDirection = theDirection;
}


void Motor::stop() {
    this->myCurrentSpeed = 0;
}


float Motor::getSpeed() {
    return this->myCurrentSpeed;
}

Direction Motor::getDirection() {
    return this->myDirection;

}

int Motor::getId() {
    return this->myId;
}


void Motor::turnRight() {
    myDirection = static_cast<Direction>((static_cast<int>(myDirection) + 1) % 4);
}

void Motor::turnLeft() {
    myDirection = static_cast<Direction>((static_cast<int>(myDirection) + 3) % 4);
}


