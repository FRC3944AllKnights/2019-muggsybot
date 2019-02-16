#include "LittleSuck.h"

LittleSuck::LittleSuck(){
};

void LittleSuck::init(){
    smolsucker.Set(ControlMode::PercentOutput, 0);
    releaseValve.Set(false);
};

void LittleSuck::manualSuck(bool on, bool off){
    if (on){
        sucking = true;
    }
    if (off){
        sucking = false;
    }
    if(sucking){
        smolsucker.Set(ControlMode::PercentOutput, suckSpeed);
        releaseValve.Set(false);
    }
    else{
        smolsucker.Set(ControlMode::PercentOutput, 0);
        releaseValve.Set(true);
    }
};