#ifndef MOTOR_MECH_CAR
#define MOTOR_MECH_CAR

/**
 * Direction
 * Represents the possible directions a motor can rotate or move.
 *
 * This enum is used to indicate the orientation of the motor's movement.
 */
enum class Direction {
    NORTH, 
    SOUTH, 
    EAST,  
    WEST   
};

/**
 * Motor
 * Represents a single motor in the car.
 *
 * The Motor class encapsulates the state and behavior of a motor,
 * including its speed, direction, and unique identifier.
 * Each motor can be controlled independently to achieve complex
 * car movements when combined with other motors.
 */
class Motor {
public:
    /**
     * Construct a new Motor object.
     * 
     * @param theId Unique identifier for this motor.
     */
    Motor(const int theId);

    /**
     * Destructor for Motor.
     *
     * Defaulted since no special cleanup is required.
     */
    ~Motor() = default;

    /**
     * Stop the motor by setting its speed to zero.
     */
    void stop();

    /**
     * Get the current speed of the motor.
     * 
     * @return Current speed as a float.
     */
    float getSpeed();

    /**
     * Get the current direction of the motor.
     * 
     * @return Current direction as a Direction enum.
     */
    Direction getDirection();

    /**
     * Get the unique identifier of the motor.
     * 
     * @return Motor ID as an integer.
     */
    int getId();

    /**
     * Set the direction of the motor.
     * 
     * @param theDirection Desired direction.
     */
    void setDirection(const Direction theDirection);

    /**
     * Set the speed of the motor.
     * 
     * @param theSpeed Desired speed as a float.
     */
    void setSpeed(const float theSpeed);

private:
    // Current speed of the motor
    float myCurrentSpeed;   

    // Current direction of the motor
    Direction myDirection;  

    // Unique identifier for the motor
    const int myId;         
};

#endif 
