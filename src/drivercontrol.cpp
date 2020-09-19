#include "vex.h"
#include "configvalues.h"
#include "functions.h"

using namespace vex;

void drivercontrol()
{
  while(true)
  {
    inertialDebug();

    if(Controller.ButtonA.pressing())
    {
      inertialTurn(right, 90, 50);
    }

    if(Controller.ButtonB.pressing())
    {
      PIDTurn(leftMotors, rightMotors, 180, 180, 3, 0.5, 0.005, 0.05, inertialSensor, 15, false);
    }

    if(Controller.ButtonY.pressing()) 
    {
      autonomous();
      wait(5, sec);
    }
  }
}