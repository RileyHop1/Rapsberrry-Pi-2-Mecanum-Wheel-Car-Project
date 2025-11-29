#include "Car.h"

CarController* CarController::myInstance = nullptr;

Motor CarController::myMotorBackLeft(1);
Motor CarController::myMotorBackRight(2);
Motor CarController::myMotorFrontLeft(3);
Motor CarController::myMotorFrontRight(4);


CarController* CarController::Instance() {
    if (myInstance == nullptr) {
        myInstance = new CarController;
    }

    return myInstance;
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
}

void CarController::turnRight(const float theSpeed) {
    myMotorBackLeft.setSpeed(theSpeed);
    myMotorBackRight.stop();
    myMotorFrontLeft.setSpeed(theSpeed);
    myMotorFrontRight.stop();
}

void CarController::stop() {
    myMotorBackLeft.stop();
    myMotorBackRight.stop();
    myMotorFrontLeft.stop();
    myMotorFrontRight.stop();
}