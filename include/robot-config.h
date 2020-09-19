using namespace vex;

extern brain Brain;
extern brain::lcd LCD;
extern controller::lcd ControllerLCD;

extern competition Competition;
extern task Task;
extern color Color;

extern controller Controller;

extern motor frontLeftMotor;
extern motor frontRightMotor;
extern motor backLeftMotor;
extern motor backRightMotor;

extern motor_group leftMotors;
extern motor_group rightMotors;

extern inertial inertialSensor;

extern drivetrain mainDrivetrain;

extern timer t1;

void vexcodeInit(void);
void autonomous(void);
void drivercontrol(void);