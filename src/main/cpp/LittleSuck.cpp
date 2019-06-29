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
        releaseValve.Set(false);
        if (pressure.GetAverageVoltage() < .95){
            smolsucker.Set(ControlMode::PercentOutput, suckSpeed);
        }
        else{
            smolsucker.Set(ControlMode::PercentOutput, 0);
        }    
    }
    else{        
        smolsucker.Set(ControlMode::PercentOutput, 0);
        releaseValve.Set(true);
    }

    frc::SmartDashboard::PutNumber(" Voltage ", pressure.GetAverageVoltage());

    if (count >= 100){
        vac = pressure.GetAverageVoltage();
        sb.append("\tValue: ");
	    sb.append(std::to_string(vac));
        printf("%s\n", sb.c_str());
        sb = "";
        count = 0;
    }
};