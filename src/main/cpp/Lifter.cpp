#include "Lifter.h"

Lifter::Lifter(){
};

 void Lifter::init(){
     lifterServo.Set(liftHoldAngle);
     armServo.Set(armHoldAngle);
};

 void Lifter::manualLift(bool foward, bool reverse){
    if (foward) {
        lifterServo.Set(liftReleaseAngle);
        armServo.Set(armReleaseAngle);
        if(lifterServo.Get() < liftReleaseAngle - 0.05){
            longlifty.Set(ControlMode::PercentOutput, 0);
        }
        else if(limitSwitch.Get() == true){
            longlifty.Set(ControlMode::PercentOutput, growthspeed);
        }
        else{
            longlifty.Set(ControlMode::PercentOutput, 0);
        }
    }
    else if (reverse) {
        longlifty.Set(ControlMode::PercentOutput, -growthspeed*.5);
    }

    else {
        longlifty.Set(ControlMode::PercentOutput, 0);
    }
};

