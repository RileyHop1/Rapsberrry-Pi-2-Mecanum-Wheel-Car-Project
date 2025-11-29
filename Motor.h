#ifndef MOTOR_MECH_CAR
#define MOTOR_MECH_CAR

enum class Direction{
    NORTH,
    SOUTH,
    EAST,
    WEST
};


/**This the motor class it....  */
class Motor {
public:

    motor(const int theId);
    ~motor();

    void stop();


    float getSpeed();
    Direction getDirection();
    int getId();


    void setDriection(const Direction theDirection);
    void setSpeed(const float theSpeed);
private:
    float myCurrentSpeed;
    Direction myDirection;
    const int myId;
};



#endif