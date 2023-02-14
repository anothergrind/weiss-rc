#pragma region VEXcode Generated Robot Configuration

// Required C++ Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Vex imports 
#include "vex.h"
using namespace vex;

// Brain should be defined by default
brain Brain;

// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration 
controller Controller1 = controller(primary);

motor Vertical = motor(PORT3, ratio36_1, false);
motor SuccZucc = motor(PORT4, ratio18_1, true);
motor Roller = motor(PORT5, ratio36_1, true);
motor Abuser = motor(PORT6, ratio18_1, false);
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);

drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);


// Define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Biar                                                      */
/*    Created:      2/14/2023                                                 */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void leftJoystickChanged() {
  Left.setVelocity((int)((Controller1.Axis3.position() + Controller1.Axis4.position()) / 2.0), percent);
  Right.setVelocity((int)((Controller1.Axis3.position() - Controller1.Axis4.position()) / 2.0), percent);
}

void rightJoystickChanged() {
  Vertical.setVelocity(Controller1.Axis2.position() / 2, percent);
}

void startSuccZucc() {
  SuccZucc.setVelocity(60, percent);
}

void endSuccZucc() {
  SuccZucc.setVelocity(0, percent);
}

//Note: CW means Clockwise; CCW means Counter Clock
void turnBoyCW(double num){
  Left.spinFor(reverse, num, turns);
  Right.spinFor(forward, num, turns);
}

void moveForward(double amount){
  Left.spinFor(forward, amount, turns);
  Right.spinFor(forward, amount, turns);
  SuccZucc.spin(forward);
}

void autoMan(){
  SuccZucc.spin(forward);
  Drivetrain.driveFor(forward, 3, turns);
  Drivetrain.turnFor(right, 45, degrees)
  Drivetrain.driveFor(forward, 3, turns)
  Vertical.spin(forward);
  turnBoyCW(1.62);
  moveForward(0.5);
}

void vroomVroom(){
  Left.spin(forward);
  Right.spin(forward);
  Vertical.spin(forward);
  SuccZucc.spin(forward);

  Left.setVelocity(0, percent);
  Right.setVelocity(0, percent);
  Vertical.setVelocity(0, percent);
  SuccZucc.setVelocity(0, percent);

  Controller1.Axis3.changed(leftJoystickChanged);
  Controller1.Axis4.changed(leftJoystickChanged);
  Controller1.Axis2.changed(rightJoystickChanged);
  Controller1.ButtonR1.pressed(startSuccZucc);
  Controller1.ButtonR2.pressed(endSuccZucc);
}

int main() {
  Abuser.setVelocity(100, percent);
  Abuser.spinFor(forward, 150, degrees);
  Abuser.spinFor(reverse, 150, degrees);
}
