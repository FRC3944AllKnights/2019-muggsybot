#include "Lifter.h"

Lifter::Lifter(){
};

 void Lifter::init(){
     safetyServo.Set(holdAngle);
};

 void Lifter::manualLift(bool foward, bool reverse){
    if (foward) {
        safetyServo.Set(releaseAngle);
        if(safetyServo.Get() < releaseAngle - 0.05){
            longlifty.Set(ControlMode::PercentOutput, 0);
        }
        else{
            longlifty.Set(ControlMode::PercentOutput, -growthspeed);
        }
    }
    else if (reverse) {
        longlifty.Set(ControlMode::PercentOutput, growthspeed*.25);
    }

    else {
        longlifty.Set(ControlMode::PercentOutput, 0);
    }
};

