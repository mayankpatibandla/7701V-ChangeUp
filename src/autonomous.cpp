#include "vex.h"
#include "configvalues.h"
#include "functions.h"

using namespace vex;

void autonomous()
{
  if(skills) //skills auton
  {
    inertialDebug();
    inertialTurn(right, 90, 50);
  }
  else if(team) //red autons
  {
    if(side) //right side
    {

    }
    else //left side
    {

    }
  }
  else //blue autons
  {
    if(side) //right side
    {

    }
    else //left side
    {

    }
  }
}