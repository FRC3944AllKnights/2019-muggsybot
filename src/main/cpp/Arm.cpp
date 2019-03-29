#include "Arm.h"

Arm::Arm(){
};

 void Arm::init(){
    };

 void Arm::manualRotate(bool foward, bool reverse, int count){
    if (foward) {
        armMotor.Set(ControlMode::PercentOutput, -rotatespeed);
    }
    else if (reverse) {
        armMotor.Set(ControlMode::PercentOutput, rotatespeed);
    }

    else {
        armMotor.Set(ControlMode::PercentOutput, 0);
    }
    if (count >= 100){
        armPosition = pot.GetAverageVoltage();
        sb.append("\tArm Position: ");
	    sb.append(std::to_string(armPosition));
        printf("%s\n", sb.c_str());
        sb = "";
    }
};
