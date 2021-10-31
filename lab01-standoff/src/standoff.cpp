#include "standoff.h"
#include "ir_codes.h"
#include "IRdecoder.h"

IRDecoder decoder;

void StandoffController::processDistanceReading(float distance)
{
    float error = targetDistance - distance;
    float effort = piStandoffer.CalcEffort(error);
    leftEffort = effort;
    rightEffort = effort;

    // Serial.print(targetDistance);
    // Serial.print('\t');
    // Serial.print(distance);
    // Serial.print('\t');
    // Serial.print(error);
    // Serial.print('\t');
    // Serial.print(effort);
    // Serial.print('\t');
    // Serial.print(leftEffort);
    // Serial.print('\t');
    // Serial.print(rightEffort);
    // Serial.print('\t');
}

void StandoffController::handleKeyPress(int16_t key)
{
    switch(key)
    {
        case remoteUp:
            targetDistance += 10;
            break;

        case remoteDown:
            targetDistance -= 10;
            break;

        default:
            if(key >= remote0 && key <= remote9)
            {
                targetDistance = (key-16)*10; 
            }
            break;
    }
}