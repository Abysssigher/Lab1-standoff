#include "robot.h"

// NOTE THAT MY IR KEYS AND CODES ARE DIFFERENT FROM YOURS!!! Add/adust as needed
#include "ir_codes.h"
#include "Rangefinder.h"
#include <maxbotix.h>
#include <IRdecoder.h>
Rangefinder rangefinder;
StandoffController standoffController;
Robot::Robot(void)
{
    //nothing to see here; move along...
}

void Robot::init(void)
{
    chassis.init();

    irDecoder.init(IR_PIN);
    mb_ez1.init(USE_ECHO);  // TODO: use the sensor/method of your choice
    rangefinder.attach(15,10);//(trigger pin, echo pin)
}

void Robot::loop() 
{
    float currDistance = rangefinder.getDistanceCM();

    //check the IR remote
    int16_t key = irDecoder.getKeyCode();
    if(key != -1) {handleIRPress(key);}
    
    //check the distance sensor
    //bool newReading = ;//what we have for ultrasonic rangefinder
    //if(newReading) {
    //handle the data

    handleNewDistanceReading(currDistance);
    //}


    // float distanceReading = 0;
    // bool hasNewReading = mb_ez1.getDistance(distanceReading);
    // if(hasNewReading) handleNewDistanceReading(distanceReading);
}

void Robot::handleIRPress(int16_t key)
{
    Serial.println(key);
    //if(key == MUTE)
    if(key == remoteStopMode)
    {
        chassis.stop();
        robotState = ROBOT_IDLE;
        return;
    }

    switch(robotState)
    {
        case ROBOT_IDLE:
            //if(key == BACK)
            if(key == remoteLeft)
            {
                robotState = ROBOT_STANDOFF;
            }
            //if(key == PREV)
            // if(key == remoteRight)
            // {
            //     robotState = ROBOT_WALL_FOLLOWING;
            // }
            // break;
        case ROBOT_STANDOFF:
            standoffController.handleKeyPress(key);
            break;
        //TODO: Add case for wall following
    }
}

void Robot::handleNewDistanceReading(float distanceReading)
{
    //comment out after you verify this works
    Serial.print(millis());
    Serial.print('\t');
    Serial.print(distanceReading);
    Serial.print('\t');
    
    //TODO: Add wall following behaviour

    if(robotState == ROBOT_STANDOFF)
    {
        standoffController.processDistanceReading(distanceReading);
        chassis.setMotorEfforts(standoffController.leftEffort, standoffController.rightEffort);
        // if (abs(distanceReading - targetDistance) < 1){
        //      chassis.setMotorEfforts(0,0);
        //      robotState = ROBOT_IDLE;
        //}
    }   
    Serial.print('\n');
}