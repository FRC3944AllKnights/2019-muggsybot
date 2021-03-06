#ifndef LITTLESUCK_H
#define LITTLESUCK_H

#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>
#include "frc/AnalogInput.h"
#include <frc/SmartDashboard/SmartDashboard.h>

class LittleSuck{
    public:
        LittleSuck();
        void init();
        void manualSuck(bool on, bool off);

    private:
        WPI_TalonSRX smolsucker{13};
        frc::Solenoid releaseValve{0};
        frc::AnalogInput pressure{1};
        double suckSpeed = 0.20; 
        bool sucking = true;
        int count;
        double vac;
        std::string sb;
};

#endif