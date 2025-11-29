#include "Motor.h"



Motor::Motor(const int theId) : myId(theId) {
    //We don't need anything here.

}

void Motor::setSpeed(const float theSpeed) {
    this->myCurrentSpeed = theSpeed;
}


void Motor::setDriection(const Direction theDirection) {
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