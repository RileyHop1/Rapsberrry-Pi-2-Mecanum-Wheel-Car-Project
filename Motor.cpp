#include "Motor.h"



Motor::Motor(const int theId) : myId(theId) {
    //We don't need anything here.

}

Motor::setSpeed(const float theSpeed) {
    this.myCurrentSpeed = theSpeed;
}


Motor::setDriection(const Direction theDirection) {
    this.myDirection = theDirection;
}


Motor::stop() {
    this.theSpeed = 0;
}


Motor::getSpeed() {
    return this.myCurrentSpeed;
}

Motor::getDirection() {
    return this.myDirection

}
 Motor::getId() {
    return this.myId;
 }