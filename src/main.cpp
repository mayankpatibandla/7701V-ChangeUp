#include "vex.h"
#include "configvalues.h"
#include "functions.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace vex;

std::ifstream ifs;
char data[100];

int main() 
{
  vexcodeInit();

  LCD.clearScreen();
  LCD.render();

  if(Brain.SDcard.isInserted())
  {
    ifs.open("config.txt", std::ifstream::in);
    LCD.clearScreen();
    LCD.printAt(20, 30, "Loading config file");
    LCD.render();

    wait(1, sec);
    
    LCD.clearScreen();
    ifs >> data;
    LCD.printAt(20, 30, "1: %c", data[0]);
    team = charToBool(data[0]);
    ifs >> data;
    LCD.printAt(20, 45, "2: %c", data[0]);
    side = charToBool(data[0]);
    ifs >> data;
    LCD.printAt(20, 60, "3: %c", data[0]);
    skills = charToBool(data[0]);
    ifs >> data;
    LCD.printAt(20, 75, "4: %c", data[0]);
    ifs >> data;
    LCD.printAt(20, 90, "5: %c", data[0]);
    ifs >> data;
    LCD.printAt(20, 115, "6: %c", data[0]);
    ifs >> data;
    LCD.printAt(20, 130, "7: %c", data[0]);
    ifs >> data;
    LCD.printAt(20, 145, "8: %c", data[0]);
    LCD.render();

    wait(5, sec);

    LCD.clearScreen();
    Brain.Screen.print("Config file loaded");
    LCD.render();
  }
  else 
  {
    LCD.print("No SD Card");
    ControllerLCD.print("No SD Card");
    LCD.render();
  }
  ifs.close();

  wait(2.5, sec);

  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);

  while(true) {
    Task.sleep(20);
  }    
}