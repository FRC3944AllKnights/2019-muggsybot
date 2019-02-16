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
    armPosition = pot.Get();
    sb.append("\tArm Position: ");
	sb.append(std::to_string(armPosition));
    if (count >= 10){
        printf("%s\n", sb.c_str());
    }
};
