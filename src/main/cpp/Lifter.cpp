#include "Lifter.h"

Lifter::Lifter(){
};

 void Lifter::init(){
    };

 void Lifter::manualLift(bool foward, bool reverse){
    if (foward) {
        longlifty.Set(ControlMode::PercentOutput, -growthspeed);
    }
    else if (reverse) {
        longlifty.Set(ControlMode::PercentOutput, growthspeed * .25);
    }

    else {
        longlifty.Set(ControlMode::PercentOutput, 0);
    }
};

