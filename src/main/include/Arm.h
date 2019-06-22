#ifndef ARM_H
#define ARM_H

#include <ctre/Phoenix.h>
#include "frc/AnalogInput.h"

class Arm{
    public:
        Arm();
        void init();
        void manualRotate(bool foward, bool reverse, int count);

    private:
        WPI_TalonSRX armMotor{15};
        frc::AnalogInput pot {3};
        double rotatespeed = .3;
        double armPosition = 0;
        std::string sb;
};

#endif