#ifndef CAR_CONTROLLER
#define CAR_CONTROLLER



class CarController {
public:

    static CarController* Instance();

    static void moveForward(const float theSpeed);
    static void moveBackward(const float theSpeed);
    static void turnLeft(const float theSpeed);
    static void turnRight(const float theSpeed);

    static void stop();



    ~CarController();
private:

    
    //Implementing singleton
    CarController();

    static CarController* myInstance = nullptr;

    
    static Motor myMotorBackLeft;
    static Motor myMotorBackRight;
    static Motor myMotorFrontLeft;
    static Motor myMotorFrontRight;








};














#endif