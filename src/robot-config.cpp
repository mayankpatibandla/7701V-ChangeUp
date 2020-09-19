#include "vex.h"

using namespace vex;

brain Brain;
brain::lcd LCD;
controller::lcd ControllerLCD;

competition Competition;
task Task;
color Color;

controller Controller = controller(primary);

motor frontLeftMotor = motor(PORT1, ratio18_1, false);
motor frontRightMotor = motor(PORT2, ratio18_1, true);
motor backLeftMotor = motor(PORT3, ratio18_1, false);
motor backRightMotor = motor(PORT4, ratio18_1, true);

motor_group leftMotors = motor_group(frontLeftMotor, backLeftMotor);
motor_group rightMotors = motor_group(frontRightMotor, backRightMotor);

inertial inertialSensor = inertial(PORT10);

drivetrain mainDrivetrain = drivetrain(leftMotors, rightMotors);

timer t1;

void vexcodeInit(void) 
{
  LCD.setCursor(1, 1);
  inertialSensor.calibrate();
  LCD.print("Calibrating Inertial Sensor");
  LCD.render();
  while (inertialSensor.isCalibrating()) {
    wait(100, msec);
  }
}