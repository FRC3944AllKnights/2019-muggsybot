#ifndef ARM_H
#define ARM_H

#include <ctre/Phoenix.h>
#include "frc/AnalogPotentiometer.h"

class Arm{
    public:
        Arm();
        void init();
        void manualRotate(bool foward, bool reverse, int count);

    private:
        WPI_TalonSRX armMotor{14};
        frc::AnalogPotentiometer pot{0, 180, 30};
        double rotatespeed = .3;
        double armPosition = 0;
        std::string sb;
};

#endif