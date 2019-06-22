#include "LittleSuck.h"

LittleSuck::LittleSuck(){
};

void LittleSuck::init(){
    smolsucker.Set(ControlMode::PercentOutput, 0);
    releaseValve.Set(false);
    count = 0;
};

void LittleSuck::manualSuck(bool on, bool off){
    count = count + 1;
    if (on){
        sucking = true;
    }
    if (off){
        sucking = false;
    }
    if(sucking){
        //bigboi
        if(pressure.GetAverageValue() > 0.95){
            smolsucker.Set(ControlMode::PercentOutput, suckSpeed);
            releaseValve.Set(false);
        }
        else{
            smolsucker.Set(ControlMode::PercentOutput, 0);
            releaseValve.Set(true);
        }    
    }
    else{        
        smolsucker.Set(ControlMode::PercentOutput, 0);
        releaseValve.Set(true);
    }
    if (count >= 100){
        vac = pressure.GetAverageValue();
        sb.append("\tValue: ");
	    sb.append(std::to_string(vac));
        printf("%s\n", sb.c_str());
        sb = "";
        count = 0;
    }
};