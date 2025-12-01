#include "Car.h"

CarController* CarController::myInstance = nullptr;

Motor CarController::myMotorBackLeft(1);
Motor CarController::myMotorBackRight(2);
Motor CarController::myMotorFrontLeft(3);
Motor CarController::myMotorFrontRight(4);

Point CarController::myPos = Point(0, 0);


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
    delete myInstance;
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