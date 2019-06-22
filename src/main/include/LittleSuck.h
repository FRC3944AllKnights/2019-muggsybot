#ifndef LITTLESUCK_H
#define LITTLESUCK_H

#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>
#include "frc/AnalogInput.h"

class LittleSuck{
    public:
        LittleSuck();
        void init();
        void manualSuck(bool on, bool off);

    private:
        WPI_TalonSRX smolsucker{13};
        frc::Solenoid releaseValve{0};
        frc::AnalogInput suckSensor{0};
        double suckSpeed = 0.15; 
        bool sucking = false;
};

#endif