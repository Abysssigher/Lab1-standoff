#include <Arduino.h>
#include <RBE-200n-Lib.h>
#include "Rangefinder.h"
#include "robot.h"

Robot robot;
StandoffController standoffcontroller;
float targetDistance = 50;
float currDistance;


void setup() 
{
  Serial.begin(115200);
  delay(500);
  robot.init();
}

void loop()
{

  robot.loop();
  // //get ultrasonic reading
  // float currDistance = rangefinder.getDistanceCM();
  // //check the current target distance if it's changing
  // if(decoder.getKeyCode() != -1){
  // robot.handleIRPress(decoder.getKeyCode());
  // //this will give us the new targetDistance
  // }
  // bool newReading = ;//what we have in the Rangefinder class.
  // //send the robot to target position if the position of robot is changing
  // if(newReading) {
  //   //handle the data
  //   robot.handleNewDistanceReading(currDistance);
  //   }
}