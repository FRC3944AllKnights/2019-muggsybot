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
<<<<<<< HEAD
<<<<<<< HEAD
        frc::AnalogInput pressure{1};
        double suckSpeed = 0.20; 
=======
=======
>>>>>>> parent of 2fe2370... most up to date
        frc::AnalogInput pressure{0};
        double suckSpeed = 0.25; 
>>>>>>> parent of 2fe2370... most up to date
        bool sucking = true;
        int count;
        double vac;
        std::string sb;
};

#endif