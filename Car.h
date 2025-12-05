#ifndef CAR_CONTROLLER
#define CAR_CONTROLLER

#include "Motor.h"
#include "Camera.h"
#include <iostream>


/**
 * This is a point struct it holds
 * A xPos and yPos.
 */
struct Point {
    float xPos;
    float yPos;

    Point(const float theXpos, const float theYpos): 
        xPos(theXpos), yPos(theYpos) {}
};

/**
 * @class CarController
 * A singleton class that manages and controls the car's motors.
 *
 * The CarController provides high-level movement commands (forward, backward,
 * turning, stopping) by coordinating four Motor instances representing each wheel.
 * It is implemented as a singleton to ensure only one controller instance exists.
 */
class CarController {
public:
    /**
     * Get the singleton instance of CarController.
     * 
     * If no instance exists yet, one will be created. This ensures
     * centralized control of the car's motors.
     * 
     * @return Pointer to the CarController singleton instance.
     */
    static CarController* Instance();

    /**
     * Move the car forward at the given speed.
     * 
     * @param theSpeed Speed value to set for all motors (positive float).
     */
    void moveForward(const float theSpeed);

    /**
     * Move the car backward at the given speed.
     * 
     * @param theSpeed Speed value to set for all motors (positive float).
     */
    void moveBackward(const float theSpeed);

    /**
     * Turn the car left.
     * 
     * The left-side motors are stopped, while the right-side motors
     * are set to the given speed to pivot the car left.
     * 
     * @param theSpeed Speed value for turning (positive float).
     */
    void turnLeft(const float theSpeed);

    /**
     * Turn the car right.
     * 
     * The right-side motors are stopped, while the left-side motors
     * are set to the given speed to pivot the car right.
     * 
     * @param theSpeed Speed value for turning (positive float).
     */
    void turnRight(const float theSpeed);

    /**
     * Stop all motors, bringing the car to a halt.
     */
    void stop();

    /**
     * Get the Xpos object
     * 
     * @return float 
     */
    float getXpos();
    /**
     * Get the Ypos object
     * 
     * @return float 
     */
    float getYpos();

    /**
     * Set the Ypos object
     * 
     * @param theY 
     */
    void setYpos(const float theY);

    /**
     * Set the Xpost object
     * 
     * @param theX 
     */
    void setXpos(const float theX);

    /**
     * Updates the robot
     * based on speeds of motors.
     * 
     */
    void update();

    Direction getDirection();

    void printDriection();

    void reset();

    Camera& getCamera() { return myCamera; }


    /**
     * Destructor for CarController.
     *
     * Defaulted since no special cleanup is required.
     */
    ~CarController();

private:
    /**
     *  Private constructor to enforce singleton pattern.
     *
     * Prevents direct instantiation of CarController outside of Instance().
     */
    CarController();

    // Singleton instance pointer.
    static CarController* myInstance;

    // Motor controlling the back-left wheel.
    static Motor myMotorBackLeft;

    // Motor controlling the back-right wheel.
    static Motor myMotorBackRight;

    // Motor controlling the front-left wheel.
    static Motor myMotorFrontLeft;

    // Motor controlling the front-right wheel.
    static Motor myMotorFrontRight;

    // Position of the car.
    static Point myPos;

    //Easy Check to see if the car is turning
    static bool myTurning;

    //give car a camera
    Camera myCamera; 
};

#endif
